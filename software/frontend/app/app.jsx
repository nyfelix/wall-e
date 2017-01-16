import React from 'react';
import MuiThemeProvider from 'material-ui/styles/MuiThemeProvider';
import WheelControl from './WheelControl.jsx';

class App extends React.Component {
   render() {
      return (
        <MuiThemeProvider>
          <WheelControl />
        </MuiThemeProvider>
      );
   }
}

export default App;
