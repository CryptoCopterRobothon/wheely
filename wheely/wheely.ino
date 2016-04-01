#include "MeOrion.h"

MeDCMotor motor1(M1);
MeLineFollower lineFinder(PORT_3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Motors(lineFinder.readSensors());
}
