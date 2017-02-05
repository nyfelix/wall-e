/*
 * Websocket interface for Arduni Yui Cloud communicaiton
 * @author Felix Nyffenegger
 */

var WebSocketServer = require('ws').Server;
var SerialPort = require('serialport');

var wss = new WebSocketServer({ port: 8081 });
var Port = SerialPort;

// Declare Websocket and Serial Port
var gws = undefined
var serial = undefined;

///////////////////////////////////////////////////////////////
// Create Websocket Server

wss.on('connection', function connection(ws) {
  gws = ws;
  ws.on('message', function incoming(message) {
    console.log('received: %s', message);
    if(serial){
  		serial.write(message + "\r\n");
      console.log('Sent to Arduino: %s', message);
  	} else {
      ws.send(message);
    }
  });

  console.log('Websocket Connected: ' + ws.address);
  ws.send('Connection successful');
});

///////////////////////////////////////////////////////////////
// Create Serial Port Server

//var serialName = '/dev/ttyATH0'; // for my YUN (the same for everyone)
//var serialName = '/dev/cu.usbmodemfd141'; // for my laptop (different for everyone)

SerialPort.list(function (err, ports) {
  ports.forEach(function(port) {
      console.log(port.comName);
      console.log(port.manufacturer);
      if (port.manufacturer && port.manufacturer.startsWith("Arduino")) {
        // create the port
        serial = new Port(port.comName,{
        	'baudrate':9600, // the Arduino's baud rate
        	'parser' : SerialPort.parsers.readline('\r\n') // arduino ends messages with .println()
        });

        // this event fires when the serial port opens
        serial.on('open',function(){
        	console.log('Serial port is OPEN');
        	//serial.isOpen = true; // our own little variable, to tell us the port opened
        });

        // this event fires when we get data from the arduino
        serial.on('data',function(data){
        	console.log('Arduino sent: ' + data);
        	if(gws){
        		gws.send(data);
        	}
        	// else, just print it out so we can see it
        	else{
        		//console.log('No WebSocket connection to send: ' + data);
        	}
        });
      };
  });
  if (serial == undefined) {
    console.log("No Arduino found on serial connection.");
    console.log("Websocket will just return the value you sent...");
  }
});
