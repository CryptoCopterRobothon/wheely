void Motors(left, right) {
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
  Motors(left
}

