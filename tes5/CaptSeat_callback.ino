void CaptSeat_R_For_PopCallback(void *ptr)    {
  Serial2.write (3);
  Serial.println ("3");
}
void CaptSeat_R_For_PushCallback(void *ptr)    {
  Serial2.write (4);
  Serial.println ("4");
}

void CaptSeat_R_Rev_PopCallback(void *ptr)    {
  Serial2.write (3);
  Serial.println ("3");
}
void CaptSeat_R_Rev_PushCallback(void *ptr)    {
  Serial2.write (5);
  Serial.println ("5");
}


void CaptSeat_L_For_PopCallback(void *ptr)    {
  Serial2.write (0);
  Serial.println ("0");
}
void CaptSeat_L_For_PushCallback(void *ptr)    {
  Serial2.write (2);
  Serial.println ("2");
}

void CaptSeat_L_Rev_PopCallback(void *ptr)    {
  Serial2.write (0);
  Serial.println ("0");
}
void CaptSeat_L_Rev_PushCallback(void *ptr)    {
  Serial2.write (1);
  Serial.println ("1");
}
