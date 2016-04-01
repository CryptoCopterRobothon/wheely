#include "MeOrion.h"

/*
 * 0: innerhalb
 * 1: rechts
 * 2: links
 * 3: außerhalb
 */
 uint8_t lineDirection = 0;
 uint8_t motor_default = 20;
 uint8_t left = 0;
 uint8_t right = 0;

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
