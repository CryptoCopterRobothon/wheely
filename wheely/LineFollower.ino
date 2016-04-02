void followLine(){
  int sensorState = lineFinder.readSensors();
  Serial.println(sensorState);
  switch(sensorState)
  {
    case S1_IN_S2_IN: 
      //Serial.println("Sensor 1 and 2 are inside of black line"); 
      Motors(motor_default,motor_default);
      lineDirection = 0;
      break;
    case S1_IN_S2_OUT: 
      //Serial.println("Sensor 2 is outside of black line"); 
      Motors(motor_default,0);
      lineDirection = 1;
      break;
    case S1_OUT_S2_IN:
      Serial.println("Sensor 1 is outside of black line"); 
      Motors(0,motor_default);
      lineDirection = 2;
      break;
    case S1_OUT_S2_OUT: 
      //Serial.println("Sensor 1 and 2 are outside of black line");
      switch(lineDirection)
      {
        case 0: //innen: Stopp
          Motors(0,0);
          break;
        case 1: //rechts
          Motors(0,motor_default); 
          break;
        case 2: //links
          Motors(motor_default,0); 
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
    /*
    case S1_IN_S2_IN: 
      Serial.println("Sensor 1 and 2 are inside of black line"); 
      
      break;
    case S1_IN_S2_OUT: 
      Serial.println("Sensor 2 is outside of black line"); 
      
      break;
    case S1_OUT_S2_IN:
      Serial.println("Sensor 1 is outside of black line"); 
      
      break;
    */
    case S1_OUT_S2_OUT: 
      //Serial.println("Sensor 1 and 2 are outside of black line"); 
      insideCheckpointLine = false;
      
      break;
    default:  
      //Serial.println("At least one Sensor is inside of black line");
      if(!insideCheckpointLine){
        checkpointCounter++;
        if(checkpointCounter == endpoint){
          isSpin = true;
        }
      }
      insideCheckpointLine = true;
      break;
  }
}

