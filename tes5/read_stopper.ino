void Read_Stopper ()  {
  VAR_STOP_TV = digitalRead (STOP_TV);
  VAR_STOP_PG = digitalRead (STOP_PG);
  VAR_STOP_CPSL_LOCK = digitalRead (STOP_CPSL_LOCK);
  VAR_STOP_CPSL_UNLOCK = digitalRead (STOP_CPSL_UNLOCK);
  VAR_STOP_CPSL_DOWN = digitalRead (STOP_CPSL_DOWN);
  VAR_STOP_CPSL_UP = digitalRead (STOP_CPSL_UP);
  VAR_STOP_CPSR_LOCK = digitalRead (STOP_CPSR_LOCK);
  VAR_STOP_CPSR_UNLOCK = digitalRead (STOP_CPSR_UNLOCK);
  VAR_STOP_CPSR_DOWN = digitalRead (STOP_CPSR_DOWN);
  VAR_STOP_CPSR_UP = digitalRead (STOP_CPSR_UP);

}


void Print_Stopper()  {
  if (VAR_STOP_CPSL_LOCK == LOW)  {
    VAR1_STOP_CPSL_LOCK = 0;
    //Serial.println ("STOP_CPSL_LOCK LOW");
    delay (1);
  }
  if (VAR_STOP_CPSL_LOCK != LOW)  {
    VAR1_STOP_CPSL_LOCK = 1;
    //Serial.println ("STOP_CPSL_LOCK HIGH");
    delay (1);
  }
  if (VAR_STOP_CPSL_UNLOCK == LOW)  {
    VAR1_STOP_CPSL_UNLOCK = 0;
    //Serial.println ("STOP_CPSL_UNLOCK LOW");
    delay (1);
  }
  if (VAR_STOP_CPSL_UNLOCK != LOW)  {
    VAR1_STOP_CPSL_UNLOCK = 1;
    //Serial.println ("STOP_CPSL_UNLOCK HIGH");
    delay (1);
  }
  if (VAR_STOP_CPSL_DOWN == LOW)  {
    VAR1_STOP_CPSL_DOWN = 0;
    //Serial.println ("STOP_CPSL_DOWN LOW");
    delay (1);
  }
  if (VAR_STOP_CPSL_DOWN != LOW)  {
    VAR1_STOP_CPSL_DOWN = 1;
    //Serial.println ("STOP_CPSL_DOWN HIGH");
    delay (1);
  }
  if (VAR_STOP_CPSL_UP == LOW)  {
    VAR1_STOP_CPSL_UP = 0;
    //Serial.println ("STOP_CPSL_UP LOW");
    delay (1);
  }
  if (VAR_STOP_CPSL_UP != LOW)  {
    VAR1_STOP_CPSL_UP = 1;
    //Serial.println ("STOP_CPSL_UP HIGH");
    delay (1);
  }
  if (VAR_STOP_CPSR_LOCK == LOW)  {
    VAR1_STOP_CPSR_LOCK = 0;
    //Serial.println ("STOP_CPSR_LOCK LOW");
    delay (1);
  }
  if (VAR_STOP_CPSR_LOCK != LOW)  {
    VAR1_STOP_CPSR_LOCK = 1;
    //Serial.println ("STOP_CPSR_LOCK HIGH");
    delay (1);
  }
  if (VAR_STOP_CPSR_UNLOCK == LOW)  {
    VAR1_STOP_CPSR_UNLOCK = 0;
    //Serial.println ("STOP_CPSR_UNLOCK LOW");
    delay (1);
  }
  if (VAR_STOP_CPSR_UNLOCK != LOW)  {
    VAR1_STOP_CPSR_UNLOCK = 1;
    //Serial.println ("STOP_CPSR_UNLOCK HIGH");
    delay (1);
  }
  if (VAR_STOP_CPSR_DOWN == LOW)  {
    VAR1_STOP_CPSR_DOWN = 0;
    //Serial.println ("STOP_CPSR_DOWN LOW");
    delay (1);
  }
  if (VAR_STOP_CPSR_DOWN != LOW)  {
    VAR1_STOP_CPSR_DOWN = 1;
    //Serial.println ("STOP_CPSR_DOWN HIGH");
    delay (1);
  }
  if (VAR_STOP_CPSR_UP != LOW)  {
    VAR1_STOP_CPSR_UP = 1;
    //Serial.println ("STOP_CPSR_UP HIGH");
    delay (1);
  }
  if (VAR_STOP_CPSR_UP == LOW)  {
    VAR1_STOP_CPSR_UP = 0;
    //Serial.println ("STOP_CPSR_UP LOW");
    delay (1);
  }
  if (VAR_STOP_TV == HIGH)  {
    VAR1_STOP_TV = HIGH;
    Serial.println ("STOP_TV HIGH");
    varTVPosition = "bawah";
    delay (1);
  }
  if (VAR_STOP_PG == HIGH)  {
    VAR1_STOP_PG = HIGH;
    Serial.println ("STOP_PG HIGH");
    varPGPosition = "bawah";
    delay (1);
  }
}
