void Motors(uint8_t speed_left, uint8_t speed_right) {
  motor_left.run(left);
  motor_right.run(right);
  Serial.println(left); 
  Serial.println("; ");
  Serial.println(right);
}

void SetMotors(bool dir_left, bool dir_right) {
  if(left) {
    if(left < motor_default) {
      left++;
    }else if(right > motor_default) {
      right--;
    }
  }
  if(right) {
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
  double angle_start = getAngle();
  if(spin_direction) {    //Spin right
    Serial.println("Spin right entered");
    motor_left.run(20);
    motor_right.run(-20);
    while(getAngle() <
    motor_left.run(0);
    motor_right.run(0);
  }else {                 //Spin left
    motor_left.run(-20);
    motor_right.run(20);
    delay(1000);
    motor_left.run(0);
    motor_right.run(0);
  }
}
