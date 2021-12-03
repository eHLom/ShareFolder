void Read_Force () {
  FlexR = digitalRead(ForceR);
  FlexL = digitalRead(ForceL);
  if  (FlexR == HIGH) {
    Serial.println ("Force R HIGH");
  }
  if  (FlexL == HIGH) {
    Serial.println ("Force L HIGH");
  }
}
