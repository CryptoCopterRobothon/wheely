void joy_pos(){

  int16_t x = joystick.readX();
  int16_t y = joystick.readY();
  //angle = joystick.angle(); // unnötig
  //OffCenter = joystick.OffCenter(); // unnötig

  Serial.print("x: ");
  Serial.println(x);
  Serial.print("angle: ");
  Serial.println(handAngle);
  

  if(x > 20){
    hand_right();
  }else if(x < -20){
    hand_left();
  }

  if(y > 20){
    arm_up();
  }else if(y < -20){
    arm_down();    
  }else{
    arm.run(0);
  }

  
}

