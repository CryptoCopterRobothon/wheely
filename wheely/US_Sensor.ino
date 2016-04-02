void ussensor(){

  // Eventll was mit Motor stand ?! -> aufmachen
  
  int16_t dist = ultraSensor.distanceCm();
  Serial.println("Distanz: ");
  Serial.println(dist);
  if(dist < 10){
    nip_close();
  }else if(dist > 11) {
    if(dist > 30){
      nip_open();
    }else{
      nip.run(0);
    }
  }else{
    nip.run(0);
  }

  
}

