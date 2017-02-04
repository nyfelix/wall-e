import React from 'react';
import Slider from 'material-ui/Slider';

const styles = {
  root: {
    display: 'flex',
    height: 300,
    flexDirection: 'row',
    justifyContent: 'space-around',
  },
};



class WheelControl extends React.Component {

  constructor(props) {
    super(props);
    this.state = this.getInitialState();
  }

  getInitialState(){
    return {
      speedLeft : 0,
      speedRight : 1
    }
  }

  setSpeed(speed) {
    this.setState({
      speedLeft : speed
    })
  }

  render() {
    return (
    <div>
      <h1>Wall-e Remote Controll</h1>
      <div style={styles.root}>
        <Slider style={{height: 250}} min={-100} max={100} axis="y" defaultValue={0} value={this.props.speedLeft}/>
        <Slider style={{height: 250}} min={-100} max={100} axis="y" defaultValue={0} value={this.props.speedRight}/>
      </div>
    </div> )
  }
};

export default WheelControl;
