void INT_CALL_PushCallback(void *ptr){
  digitalWrite(CALL, HIGH); //intercomm call on
}
void INT_CALL_PopCallback(void *ptr){
  digitalWrite(CALL, LOW); //intercomm call off
}

void INT_TALK_PushCallback(void *ptr){
  digitalWrite(TALK, HIGH); //intercomm talk on
}
void INT_TALK_PopCallback(void *ptr){
  digitalWrite(TALK, LOW); //intercomm talk off
}
