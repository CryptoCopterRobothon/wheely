/*
 * 
 #include <Makeblock.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>

void setup() {
  // nicht mitkopieren - ist zum testen
}



MeDCMotor MotorL(M1);  
MeDCMotor MotorR(M2);
MeDCMotor Holder(PORT_1);
MeDCMotor Hand(PORT_2);
MeInfraredReceiver infraredReceiverDecode(PORT_5);

int HolderSpeed = 250;
int HandSpeed = 250;

void setup()
{
    infraredReceiverDecode.begin();
}

void loop()
{
 if(infraredReceiverDecode.available()||infraredReceiverDecode.buttonState())
    {
        switch(infraredReceiverDecode.read())
        {
         case IR_BUTTON_A:
               Holder_up();
               break;
         case IR_BUTTON_D:
               Holder_down();
               break;
         case IR_BUTTON_C:
               Hand_close();
               break;
         case IR_BUTTON_E:
               Hand_open();
               break;
        }
    }
    else
    {
      Stop();
    }
}

  

void Stop()
{
  Holder.run(0);
  Hand.run(0);
}
void Holder_up()
{
  Holder.run(HolderSpeed);
}
void Holder_down()
{
  Holder.run(-HolderSpeed);
}
void Hand_close()
{
  Hand.run(HandSpeed);
}
void Hand_open()
{
  Hand.run(-HandSpeed);
}


*/
