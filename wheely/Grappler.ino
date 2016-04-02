void nip_stop()
{
  arm.run(0);
  nip.run(0);
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!! MOTOR
// Arm
void arm_up(){
  arm.run(armSpeed);
  allowedClose =true;
}
void arm_down(){
  arm.run(-armSpeed);
  allowedClose = true;
}

// Zange
void nip_close(){
  nip.run(-nipSpeed);
}
void nip_open(){
  nip.run(nipSpeed);
}

// !!!!!!!!!!!!!!!! MOTOR
// Handgelenk
// !!!!!!!!!!!!!!!!!!!!!!!! kontrolle ob links und rechts nicht vertauscht!!!!! 
void hand_right(){
  handAngle += 3;
  if(handAngle > 180){
    handAngle = 180;
  }
  Serial.println(handAngle);
  myservo1.write(handAngle);
  delay(10);
}
void hand_left(){
  handAngle -= 3;
  if(handAngle < 0){
    handAngle = 0;
  }
  Serial.println(handAngle);
  myservo1.write(handAngle);
  delay(10);
}
