#include "MeOrion.h"
//#include <SoftwareSerial.h>

/*
 * 0: innerhalb
 * 1: rechts
 * 2: links
 * 3: außerhalb
 */
int lineDirection = 0;

uint8_t checkpointCounter = 0;

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
