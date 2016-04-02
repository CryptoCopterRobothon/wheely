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
uint8_t motor_default = 50;
uint8_t left = 0;
uint8_t right = 0;
uint8_t checkpointCounter = 0;
uint8_t endpoint = 0;
bool insideCheckpointLine = false;
bool crosswise = false;
double standardAngle;
bool isSpin = false;
//Remote
uint8_t ReceiverCode;
uint8_t buttonState;
static uint8_t PrebuttonState = 0;
// grappler
int armSpeed = 250;
int nipSpeed = 250;
int handSpeed = 250;
// ultrasonic
int16_t dist = 0; /* distance of ultrasonic */
// Joystick
int16_t x = 0;    /* a variable for the Joystick's x value */
int16_t y = 0;    /* a variable for the Joystick's y value */
float angle = 0;       /* The relative angle of XY */
float OffCenter = 0;    /* offset with the center */

// PIN / PORTS *****************
MeDCMotor arm(M1); // Arm = Arm (oben unten)
MeDCMotor nip(M2); // Nipper = Zange (auf zu)
MeDCMotor motor_right(PORT1);
MeDCMotor motor_left(PORT2);
MeLineFollower lineFinder(PORT_3);
MeLineFollower lineCounter(PORT_4);
MeDCMotor hand(PORT_5); // Hand = Handgelenk (links rechts)
MeInfraredReceiver infraredReceiverDecode(PORT_6);
MeJoystick joystick(PORT_7);
MeUltrasonicSensor ultraSensor(PORT_8);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  infraredReceiverDecode.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("Ende: ");
  Serial.println(endpoint);
  Serial.print("check: ");
  Serial.println(checkpointCounter);

  if(checkpointCounter != endpoint){
   // Serial.println("testprint");
    if(!crosswise){
      //Serial.println("follow");
      followLine();
      receive();
      countLine();
    }else{
      //Serial.println("Spin");
      if(checkpointCounter < endpoint){
        spin(0,1);
      }else{
        spin(1,1);
      }
    }
    
  }else{
    if(isSpin){
      //Serial.println("Spin");
      spin(1,1);
    }else{
      //Serial.println("Wait");
      receive();
    }
  }
}
