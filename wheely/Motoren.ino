void Motors(unsinged char sens_line) {
  switch(sens_line)
  {
    case S1_IN_S2_IN:
      Serial.println("Stop");
      motor1.run(20);
      break;
    case S1_IN_S2_OUT: Serial.println("Sensor 2 is outside of black line"); break;
    case S1_OUT_S2_IN: Serial.println("Sensor 1 is outside of black line"); break;
    case S1_OUT_S2_OUT: Serial.println("Sensor 1 and 2 are outside of black line"); break;
    default: break;
}

