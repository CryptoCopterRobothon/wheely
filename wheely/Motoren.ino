void Motors(uint8_t speed_left, uint8_t speed_right) {
  motor_left.run(left);
  motor_right.run(right);
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

void Spin(uint8_t spin_direction, uint8_t spin_amount) {
  for(uint8_t spin_count = 0; spin_count < spin_amount; spin_count++) {
    if(spin_direction) {
      
    }
  }
}

