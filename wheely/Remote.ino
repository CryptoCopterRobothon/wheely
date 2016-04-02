void receive(){
  //Serial.println("receive");
  /*
  buttonState = infraredReceiverDecode.buttonState();
  if(PrebuttonState != buttonState)
  {
    PrebuttonState = buttonState;
    Serial.print("buttonState 0x");
    Serial.println(buttonState);
  }*/
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
        allowedClose = false;
        nip_open();
        //delay(1000);
        break;
       case IR_BUTTON_E: 
        Serial.println("Press E."); 
        allowedClose = true;
        nip_close();
        //delay(1000);
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
        endpoint = 0;
        break;
       case IR_BUTTON_1: 
        Serial.println("Press 1."); 
        endpoint = 1;
        break;
       case IR_BUTTON_2: 
        Serial.println("Press 2."); 
        endpoint = 2;
        break;
       case IR_BUTTON_3: 
        Serial.println("Press 3."); 
        endpoint = 3;
        break;
       case IR_BUTTON_4: 
        Serial.println("Press 4."); 
        endpoint = 4;
        break;
       case IR_BUTTON_5: 
        Serial.println("Press 5."); 
        endpoint = 5;
        break;
       case IR_BUTTON_6: 
        Serial.println("Press 6."); 
        endpoint = 6;
        break;
       case IR_BUTTON_7: 
        Serial.println("Press 7."); 
        endpoint = 7;
        break;
       case IR_BUTTON_8: 
        Serial.println("Press 8."); 
        endpoint = 8;
        break;
       case IR_BUTTON_9: 
        Serial.println("Press 9."); 
        endpoint = 9;
        break;
       default: break;
    }
  }else{
    //stop();
  }
}

