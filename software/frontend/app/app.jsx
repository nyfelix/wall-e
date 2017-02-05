import React from 'react';
import MuiThemeProvider from 'material-ui/styles/MuiThemeProvider';
import WheelControl from './WheelControl.jsx';

class App extends React.Component {

  componentDidMount () {
      // this is an "echo" websocket service for testing pusposes
      this.connection = new WebSocket('ws://localhost:8081');
      // listen to onmessage event
      this.connection.onmessage = evt => {
        // add the new message to state
          this.setState({
          messages : this.state.messages.concat([ evt.data ])
        })
      };

      this.timerID = setInterval (
          this.connection.send( Math.random() ),
          2000
      );
    }

    componentWillUnmount() {
       clearInterval(this.timerID);
     }

    onChange(e) {
      alert("CHANGE")
    }

    render() {
      return (
        <MuiThemeProvider>
          <WheelControl speedLeft="50" speedRight="-50" onChange={this.onChange}/>
        </MuiThemeProvider>
      );
    }
}

export default App;
