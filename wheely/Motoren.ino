void Motors(uint8_t speed_left, uint8_t speed_right) {
  motor_left.run(speed_left);
  motor_right.run(speed_right);
  Serial.println(speed_left);
  //Serial.println("; ");
  //Serial.println(speed_right);
  delay(100);
}

void SetMotors(bool dir_left, bool dir_right) {
  if(dir_right) {
    if(left < motor_default) {
      left++;
    }else if(right > motor_default) {
      right--;
    }
  }
  if(dir_left) {
    if(right < motor_default) {
      right++;
    }else if(left > motor_default) {
      left--;
    }
  }
  Motors(left, right);
}

void spin(bool spin_direction, uint8_t spin_amount) {
  Serial.println("Spin entered");
  Serial.println("Spin for loop entered");
  if(!spin_direction) {    //Spin left
    Serial.println("Spin right entered");
    motor_left.run(motor_default);
    motor_right.run(-motor_default);
    while(lineFinder.readSensors() != S1_IN_S2_IN){
      if(lineCounter.readSensors() != S1_OUT_S2_OUT){
        checkpointCounter --;
        insideCheckpointLine = true;
      }else{
        insideCheckpointLine = false;
      }
    }
    motor_left.run(0);
    motor_right.run(0);
    isSpin = false;
    crosswise = !crosswise;
  }else {                 //Spin right
    motor_left.run(-motor_default);
    motor_right.run(motor_default);
    delay(3000);
    motor_left.run(0);
    motor_right.run(0);
    isSpin = false;
    crosswise = !crosswise;
  }
}
