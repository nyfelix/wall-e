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



 const WheelControl = () => (
   <div>
     <h1>Wall-e Remote Controll</h1>
     <div style={styles.root}>
       <Slider style={{height: 250}} min={-100} max={100} axis="y" defaultValue={0} />
       <Slider style={{height: 250}} min={-100} max={100} axis="y" defaultValue={0} />
     </div>
   </div>
 );

export default WheelControl;
