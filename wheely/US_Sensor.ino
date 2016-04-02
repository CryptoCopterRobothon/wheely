void ussensor(){

  // Eventll was mit Motor stand ?! -> aufmachen
  
  uint16_t dist = ultraSensor.distanceCm();
  if(dist < 10){
    nip_close();
  }else{
    nip_stop();
  }

  
}

