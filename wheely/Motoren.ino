void Motors(bool left, bool right) {
  if(left) {
    motor_left.run(20);
    motor_right.run(0);
  }
  if(right) {
    motor_right.run(20);
    motor_left.run(0);
  }
  if(!left && !right){
    motor_right.run(0);
    motor_left.run(0);
  }
}

