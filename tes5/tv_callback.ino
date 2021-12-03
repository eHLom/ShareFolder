void TV_PushCallback(void *ptr){
  if(varTVPosition == "bawah" && varTVStatus == "berhenti")  {
    TV_Up();
    varTVStatus= "naik";
  }
  else if(varTVPosition == "atas" && varTVStatus == "berhenti")  {
    TV_Down();
    varTVStatus= "turun";
  }
  Serial.print("tv position = ");
  Serial.println(varTVPosition);
}
