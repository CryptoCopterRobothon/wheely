#include "MeOrion.h"
#include <SoftwareSerial.h>
#include <Wire.h>

#define SPIN

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

MeDCMotor motor_right(M1);
MeDCMotor motor_left(M2);
MeLineFollower lineFinder(PORT_3);
MeLineFollower lineCounter(PORT_4);
MeInfraredReceiver infraredReceiverDecode(PORT_6);
MeCompass Compass(PORT_7);
// grappler
// Arm = Arm (oben unten)
MeDCMotor arm(M1);
// Nipper = Zange (auf zu)
MeDCMotor nip(M2);
// Hand = Handgelenk (links rechts)
MeDCMotor hand(PORT_5);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Initializing I2C devices...");
  Compass.begin();
  Serial.println("Testing device connections...");
  Serial.println(Compass.testConnection() ? "HMC5883L connection successful" : "HMC5883L connection failed");
}

void loop() {
  // put your main code here, to run repeatedly:
#ifndef SPIN
  if(checkpointCounter != endpoint){
    if(!crosswise){
      followLine();
      receive();
    }else{
      
    }
    
  }else{
    if(isSpin){
      Motors(0,0);
    }else{
      receive();
    }
  }
#endif

//#ifdef SPIN
  spin(1,1);
//#endif
}
