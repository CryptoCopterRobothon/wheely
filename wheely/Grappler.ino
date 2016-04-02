void nip_stop()
{
  arm.run(0);
  nip.run(0);
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!! MOTOR
// Arm
void arm_up(){
  arm.run(armSpeed);
}
void arm_down(){
  arm.run(-armSpeed);
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
  handAngle++;
  if(handAngle > 180){
    handAngle = 180;
  }
  Serial.println(handAngle);
  myservo1.write(handAngle);
  delay(500);
}
void hand_left(){
  handAngle--;
  if(handAngle < 0){
    handAngle = 0;
  }
  Serial.println(handAngle);
  myservo1.write(handAngle);
  delay(500);
}
