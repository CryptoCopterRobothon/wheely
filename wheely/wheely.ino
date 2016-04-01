#include "MeOrion.h"

MeDCMotor motor_right(PORT1);
MeDCMotor motor_left(PORT2);
MeLineFollower lineFinder(PORT_3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  followLine();
}
