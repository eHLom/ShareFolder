void buzzer_error()  {
    for (int i = 0; i< 3; i++)  {
    digitalWrite (BUZZER, HIGH);
    delay (200);
    digitalWrite (BUZZER, LOW);
    delay (50);
  }
}
