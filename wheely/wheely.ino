#include "MeOrion.h"
#include <SoftwareSerial.h>
#include <Wire.h>

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
uint8_t checkpointCounter = 0;
uint8_t endpoint = 0;
//Remote
uint8_t ReceiverCode;
uint8_t buttonState;
static uint8_t PrebuttonState = 0;

MeDCMotor motor_right(PORT1);
MeDCMotor motor_left(PORT2);
MeLineFollower lineFinder(PORT_3);
MeLineFollower lineCounter(PORT_4);
MeInfraredReceiver infraredReceiverDecode(PORT_6);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  receive();
  if(checkpoint != endpoint){
    followLine();
  }
}
