void Motors(uint8_t speed_left, uint8_t speed_right) {
  motor_left.run(speed_left);
  motor_right.run(speed_right);
  Serial.println(speed_left);
  Serial.println("; ");
  Serial.println(speed_right);
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
  if(spin_direction) {    //Spin right
    Serial.println("Spin right entered");
    motor_left.run(20);
    motor_right.run(-20);
    delay(2000);
    motor_left.run(0);
    motor_right.run(0);
    isSpin = false;
    crosswise = !crosswise;
  }else {                 //Spin left
    motor_left.run(-20);
    motor_right.run(20);
    delay(2000);
    motor_left.run(0);
    motor_right.run(0);
    isSpin = false;
    crosswise = !crosswise;
  }
}
