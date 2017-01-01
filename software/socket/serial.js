/*
 * Websocket interface for Arduni Yui Cloud communicaiton
 * @author Felix Nyffenegger
 */

var WebSocketServer = require('ws').Server;
var SerialPort = require('serialport');

var wss = new WebSocketServer({ port: 8080 });
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
    if(serial && serial.isOpen){
		serial.write(message);
	}
  });

  console.log('Websocket Connected: ' + ws.address);
  ws.send('Connection successful');
});

///////////////////////////////////////////////////////////////
// Create Serial Port Server

//var serialName = '/dev/ttyATH0'; // for my YUN (the same for everyone)
var serialName = '/dev/cu.usbmodemfd141'; // for my laptop (different for everyone)
var serial = undefined;

// create the port
var serial = new Port(serialName,{
	'baudrate':115200, // the Arduino's baud rate
	'parser' : SerialPort.parsers.readline('\r\n') // arduino ends messages with .println()
});

// this event fires when the serial port opens
serial.on('open',function(){
	console.log('Serial port is OPEN');
	serial.isOpen = true; // our own little variable, to tell us the port opened
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
