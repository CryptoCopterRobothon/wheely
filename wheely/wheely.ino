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
uint8_t motor_default = 100;
uint8_t left = 0;
uint8_t right = 0;
uint8_t checkpointCounter = 0;
uint8_t endpoint = 0;
bool insideCheckpointLine = false;
bool crosswise = false;
double standardAngle;
bool isSpin = false;
bool allowedClose = true;

//Remote
uint8_t ReceiverCode;
uint8_t buttonState;
static uint8_t PrebuttonState = 0;

// grappler
int armSpeed = 80;
int nipSpeed = 100;
int handAngle = 90;


MeDCMotor motor_right(PORT_2);
MeDCMotor motor_left(PORT_1);
MeLineFollower lineFinder(PORT_6);
MeLineFollower lineCounter(PORT_4);
MeInfraredReceiver infraredReceiverDecode(PORT_3);
// grappler
// Arm = Arm (oben unten)
MeDCMotor arm(M1);
// Nipper = Zange (auf zu)
MeDCMotor nip(M2);
// Hand = Handgelenk (links rechts)
MePort port(PORT_5);
Servo myservo1;
int16_t servo1pin = port.pin2();
MeJoystick joystick(PORT_8);
MeUltrasonicSensor ultraSensor(PORT_7);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  infraredReceiverDecode.begin();
  myservo1.attach(servo1pin);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  Serial.print("Ende: ");
  Serial.println(endpoint);
  Serial.print("check: ");
  Serial.println(checkpointCounter);
*/
//Serial.println(allowedClose);
  if(checkpointCounter != endpoint){
   // Serial.println("testprint");
    if(!crosswise){
      //Serial.println("follow");
      followLine();
      receive();
      joy_pos();
      ussensor();
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
      joy_pos();
      ussensor();
    }
  }
}
