void followLine(){
  int sensorState = lineFinder.readSensors();
  switch(sensorState)
  {
    case S1_IN_S2_IN: 
      Serial.println("Sensor 1 and 2 are inside of black line"); 
      SetMotors(0,0);
      lineDirection = 0;
      break;
    case S1_IN_S2_OUT: 
      Serial.println("Sensor 2 is outside of black line"); 
      SetMotors(1,0);
      lineDirection = 1;
      break;
    case S1_OUT_S2_IN:
      Serial.println("Sensor 1 is outside of black line"); 
      SetMotors(0,1);
      lineDirection = 2;
      break;
    case S1_OUT_S2_OUT: 
      Serial.println("Sensor 1 and 2 are outside of black line");
      switch(lineDirection)
      {
        case 0: //innen: Stopp
          SetMotors(0,0);
          break;
        case 1: //rechts
          SetMotors(1,0); 
          break;
        case 2: //links
          SetMotors(0,1); 
          break;
        default: break;
      }
      break;
    default: break;
  }
}

void countLine(){
  int sensorState = lineCounter.readSensors();
  switch(sensorState)
  {
    case S1_IN_S2_IN: 
      Serial.println("Sensor 1 and 2 are inside of black line"); 
      
      break;
    case S1_IN_S2_OUT: 
      Serial.println("Sensor 2 is outside of black line"); 
      
      break;
    case S1_OUT_S2_IN:
      Serial.println("Sensor 1 is outside of black line"); 
      
      break;
    case S1_OUT_S2_OUT: 
      Serial.println("Sensor 1 and 2 are outside of black line");
      
      break;
    default: break;
  }
}

