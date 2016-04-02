void joy_pos(){

  uint16_t x = joystick.readX();
  uint16_t y = joystick.readY();
  //angle = joystick.angle(); // unnötig
  //OffCenter = joystick.OffCenter(); // unnötig

  if(x > 20){
    hand_right();
  }else if(x < -20){
    hand_left();
  }

  if(y > 20){
    arm_up();
  }else if(y > -20){
    arm_down();    
  }else{
    arm.run(0);
  }

  
}

