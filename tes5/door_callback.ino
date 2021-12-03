void DoorL_PushCallback(void *ptr){
  if (varDoorL == "buka") {
    digitalWrite(DL, HIGH);
    delay(500);
    digitalWrite(DL, LOW);
    varDoorL = "tutup";
  }
  if (varDoorL == "tutup")  {
    digitalWrite(DL, HIGH);
    delay(500);
    digitalWrite(DL, LOW);
    varDoorL = "buka";
  }
  Serial.println (varDoorL);
}

void DoorR_PushCallback(void *ptr){
  if (varDoorR == "buka") {
    digitalWrite(DR, HIGH);
    delay(500);
    digitalWrite(DR, LOW);
    varDoorR = "tutup";
  }
  if (varDoorR == "tutup")  {
    digitalWrite(DR, HIGH);
    delay(500);
    digitalWrite(DR, LOW);
    varDoorR = "buka";
  }
  Serial.println (varDoorR);
}
