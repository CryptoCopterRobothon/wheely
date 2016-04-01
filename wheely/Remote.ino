#include <Makeblock.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>

// Ganzer Greifarm
// Arm = Arm (oben unten)
MeDCMotor arm(PORT_1);
// Grappler = Greifer (auf zu)
MeDCMotor grap(PORT_2);
// Hand = Handgelenk (links rechts)
MeDCMotor hand(PORT_3);
MeInfraredReceiver infraredReceiverDecode(PORT_5);

// Ganzer Greifarm
int armSpeed = 250;
int grapSpeed = 250;
int handSpeed = 250;

void receive(){
  uint8_t buttonState;
  static uint8_t PrebuttonState = 0;

  buttonState = infraredReceiverDecode.buttonState();
  if(PrebuttonState != buttonState)
  {
    PrebuttonState = buttonState;
    Serial.print("buttonState 0x");
    Serial.println(buttonState);
  }
  if(infraredReceiverDecode.available())
  {
    ReceiverCode = infraredReceiverDecode.read();
    switch(ReceiverCode)
    {
       case IR_BUTTON_A: 
        Serial.println("Press A."); 
        break;
       case IR_BUTTON_B: 
        Serial.println("Press B."); 
        break;
       case IR_BUTTON_C: 
        Serial.println("Press C."); 
        break;
       case IR_BUTTON_D: 
        Serial.println("Press D."); 
        grap_open();
        break;
       case IR_BUTTON_E: 
        Serial.println("Press E."); 
        grap_close();
        break;
       case IR_BUTTON_F: 
        Serial.println("Press F."); 
        break;
       case IR_BUTTON_SETTING: 
        Serial.println("Press Setting."); 
        break;
       case IR_BUTTON_UP: 
        Serial.println("Press Up."); 
        arm_up();
        break;
       case IR_BUTTON_DOWN: 
        Serial.println("Press Down."); 
        arm_down();
        break;
       case IR_BUTTON_LEFT: 
        Serial.println("Press Left."); 
        hand_left();
        break;
       case IR_BUTTON_RIGHT: 
        Serial.println("Press Right."); 
        hand_right();
        break;
       case IR_BUTTON_0: 
        Serial.println("Press 0."); 
        break;
       case IR_BUTTON_1: 
        Serial.println("Press 1."); 
        break;
       case IR_BUTTON_2: 
        Serial.println("Press 2."); 
        break;
       case IR_BUTTON_3: 
        Serial.println("Press 3."); 
        break;
       case IR_BUTTON_4: 
        Serial.println("Press 4."); 
        break;
       case IR_BUTTON_5: 
        Serial.println("Press 5."); 
        break;
       case IR_BUTTON_6: 
        Serial.println("Press 6."); 
        break;
       case IR_BUTTON_7: 
        Serial.println("Press 7."); 
        break;
       case IR_BUTTON_8: 
        Serial.println("Press 8."); 
        break;
       case IR_BUTTON_9: 
        Serial.println("Press 9."); 
        break;
       default: break;
    }
  }else{
    stop();
  }
}

void stop()
{
  arm.run(0);
  grap.run(0);
  hand.run(0);
}

// Arm
void arm_up(){
  arm.run(armSpeed);
}
void arm_down(){
  arm.run(-armSpeed);
}

// Greifer
void grap_close(){
  grap.run(grapSpeed);
}
void grap_open(){
  grap.run(-grapSpeed);
}

// Handgelenk
// !!!!!!!!!!!!!!!!!!!!!!!! kontrolle ob links und rechts nicht vertauscht!!!!! 
void hand_right(){
  hand.run(grapSpeed);
}
void hand_left(){
  hand.run(-grapSpeed);
}

