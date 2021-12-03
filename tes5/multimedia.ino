void APPLETV_PushCallback(void *ptr){
  // channel 3
  digitalWrite(IR,HIGH);
  delay(10);
  irsend.sendNEC(0x1FE10EF,32); 
  digitalWrite(IR,LOW);
  Serial.println("send");
}

void NEXDRIVE_PushCallback(void *ptr){
  // channel 4
  digitalWrite(IR,HIGH);
  delay(10);
  irsend.sendNEC(0x1FE20DF,32); 
  digitalWrite(IR,LOW);
  Serial.println("send");
}

void DASHCAM_PushCallback(void *ptr){
  // channel 5
  digitalWrite(IR,HIGH);
  delay(10);
  irsend.sendNEC(0x1FE609F,32); 
  digitalWrite(IR,LOW);
  Serial.println("send");
}
