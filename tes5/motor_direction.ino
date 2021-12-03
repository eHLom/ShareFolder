void TV_Up ()  {
  digitalWrite (PWM_MOTOR_1, HIGH);
  digitalWrite (MOTOR_A1_PIN, HIGH);
  digitalWrite (MOTOR_B1_PIN, LOW);
  Serial.println ("TV_Up");
}

void TV_Down  ()  {
  digitalWrite (PWM_MOTOR_1, HIGH);
  digitalWrite (MOTOR_A1_PIN, LOW);
  digitalWrite (MOTOR_B1_PIN, HIGH);
  Serial.println ("TV_Down");
}

void TV_Stop  ()  {
  digitalWrite (PWM_MOTOR_1, LOW);
  digitalWrite (MOTOR_A1_PIN, LOW);
  digitalWrite (MOTOR_B1_PIN, LOW);
  Serial.println ("TV_Stop");
}

void PG_Up  ()  {
  digitalWrite (PWM_MOTOR_2, HIGH);
  digitalWrite (MOTOR_A2_PIN, HIGH);
  digitalWrite (MOTOR_B2_PIN, LOW);
  Serial.println ("PG_Up");
}
void PG_Down  ()  {
  digitalWrite (PWM_MOTOR_2, HIGH);
  digitalWrite (MOTOR_A2_PIN, LOW);
  digitalWrite (MOTOR_B2_PIN, HIGH);
  Serial.println ("PG_Down");
}
void PG_Stop  ()  {
  digitalWrite (PWM_MOTOR_2, LOW);
  digitalWrite (MOTOR_A2_PIN, LOW);
  digitalWrite (MOTOR_B2_PIN, LOW);
  Serial.println ("PG_Stop");
}

void CPSR_Up  ()  {
  digitalWrite(CPSR_PWM, HIGH);
  digitalWrite (CPSR_A, HIGH);
  digitalWrite (CPSR_B, LOW);
  Serial.println ("CPSR_Up");
  Read_Stopper();
  Print_Stopper();
}

void CPSR_Down  ()  {
  digitalWrite(CPSR_PWM, HIGH);
  digitalWrite (CPSR_A, LOW);
  digitalWrite (CPSR_B, HIGH);
  Serial.println ("CPSR_Down");
  Read_Stopper();
  Print_Stopper();
}

void CPSR_Stop  ()  {
  digitalWrite(CPSR_PWM, LOW);
  digitalWrite (CPSR_A, LOW);
  digitalWrite (CPSR_B, LOW);
  Serial.println ("CPSR_Stop");
  Read_Stopper();
  Print_Stopper();
}


void L_CPSR_Lock  ()  {
  digitalWrite (L_CPSR_PWM, HIGH);
  digitalWrite (L_CPSR_A, HIGH);
  digitalWrite (L_CPSR_B, LOW);
  Serial.println ("L_CPSR_Lock");
}

void L_CPSR_Unlock  ()  {
  digitalWrite (L_CPSR_PWM, HIGH);
  digitalWrite (L_CPSR_A, LOW);
  digitalWrite (L_CPSR_B, HIGH);
  Serial.println ("L_CPSR_Unlock");
}

void L_CPSR_Stop  ()  {
  digitalWrite (L_CPSR_PWM, LOW);
  digitalWrite (L_CPSR_A, LOW);
  digitalWrite (L_CPSR_B, LOW);
  Serial.println ("L_CPSR_Stop");
}




void CPSL_Up  ()  {
  analogWrite (CPSL_PWM, 128);
  digitalWrite (CPSL_A, HIGH);
  digitalWrite (CPSL_B, LOW);
  Serial.println ("CPSL_Up");
}

void CPSL_Down  ()  {
  analogWrite (CPSL_PWM, 128);
  digitalWrite (CPSL_A, LOW);
  digitalWrite (CPSL_B, HIGH);
  Serial.println ("CPSL_Down");
}

void CPSL_Stop  ()  {
  digitalWrite (CPSL_PWM, LOW);
  digitalWrite (CPSL_A, LOW);
  digitalWrite (CPSL_B, LOW);
  Serial.println ("CPSL_Stop");
}


void L_CPSL_Lock  ()  {
  digitalWrite (L_CPSL_PWM, HIGH);
  digitalWrite (L_CPSL_A, HIGH);
  digitalWrite (L_CPSL_B, LOW);
  Serial.println ("L_CPSL_Lock");
}

void L_CPSL_Unlock  ()  {
  digitalWrite (L_CPSL_PWM, HIGH);
  digitalWrite (L_CPSL_A, LOW);
  digitalWrite (L_CPSL_B, HIGH);
  Serial.println ("L_CPSL_Unock");
}

void L_CPSL_Stop  ()  {
  digitalWrite (L_CPSL_PWM, LOW);
  digitalWrite (L_CPSL_A, LOW);
  digitalWrite (L_CPSL_B, LOW);
  Serial.println ("L_CPSL_Stop");
}
