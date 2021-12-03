void setup_output(){
  digitalWrite(DL, LOW); //left sliding door
  digitalWrite(DR, LOW); //right sliding door
  digitalWrite(AMBIENT, LOW); //driver led plafon light
  digitalWrite(INV_PDLC, LOW);//driver inverter pdlc
  digitalWrite(PWM_MOTOR_1, LOW);// driver motor tv sleep mode
  digitalWrite(MOTOR_A1_PIN, LOW); // set pwmr motor tv low
  digitalWrite(MOTOR_B1_PIN, LOW); // set pwml motor tv low
  digitalWrite(CALL, LOW); // Call intercomm
  digitalWrite(TALK, LOW); // Talk intercomm
  digitalWrite(BUZZER, LOW); // Buzzer
  varAmbient = "mati";
  varDoorL = "buka";
  varDoorR = "buka";
  varTVPosition = "atas";
  varTVStatus = "berhenti";
  varPDLC = "mati";
  varPGPosition = "atas";
  varPGStatus = "berhenti";
  varCPSRPosition = "bawah";
  varCPSRStatus = "berhenti";
  varCPSLPosition = "bawah";
  varCPSLStatus = "berhenti";
  Read_Stopper();
  if (VAR_STOP_CPSL_LOCK == HIGH && VAR_STOP_CPSL_DOWN == HIGH)  {
    varCPSLPosition = "bawah";
    delay (1);
  }
  else if (VAR_STOP_CPSL_LOCK == HIGH && VAR_STOP_CPSL_UP == HIGH)  {
    varCPSLPosition = "atas";
    delay (1);
  }
  if (VAR_STOP_CPSR_LOCK == HIGH && VAR_STOP_CPSR_DOWN == HIGH)  {
    varCPSRPosition = "bawah";
    delay (1);
  }
  else if (VAR_STOP_CPSR_LOCK == HIGH && VAR_STOP_CPSR_UP == HIGH)  {
    varCPSRPosition = "atas";
    delay (1);
  }
  if (VAR_STOP_TV == HIGH)  {
    varTVPosition = "bawah";
    delay (1);
  }
  else if (VAR_STOP_TV != HIGH)  {
    varTVPosition = "atas";
    delay (1);
  }
  if (VAR_STOP_PG == HIGH)  {
    varPGPosition = "bawah";
    delay (1);
  }
  else if (VAR_STOP_PG != HIGH)  {
    varPGPosition = "atas";
    delay (1);
  }
}
