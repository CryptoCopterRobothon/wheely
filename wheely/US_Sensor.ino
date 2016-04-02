void ussensor(){

  // Eventll was mit Motor stand ?! -> aufmachen
  
  dist = ultraSensor.distanceCm();
  if(dist < 10){
    nip_close();
  }else{
    nip_stop();
  }

  
}

