void joy_pos(){

  x = joystick.readX();
  y = joystick.readY();
  angle = joystick.angle(); // unnötig
  OffCenter = joystick.OffCenter(); // unnötig

  if(x > 20){
    hand_right();
  }else if(x < -20){
    hand_left();
  }else{
     hand.run(0);
  }

  if(y > 20){
    arm_up();
  }else if(y > -20){
    arm_down();    
  }else{
    arm.run(0);
  }

  
}

