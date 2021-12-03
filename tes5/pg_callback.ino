void PG_PushCallback(void *ptr){
  if(varPGPosition == "bawah" && varPGStatus == "berhenti")  {
    PG_Up();
    varPGStatus = "naik";
  }
  else if(varPGPosition == "atas" && varPGStatus == "berhenti")  {
    PG_Down();
    varPGStatus = "turun";
  }
  Serial.print("pg position = ");
  Serial.println(varPGPosition);
}
