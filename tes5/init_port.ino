void init_port(){
  //lcd.begin(20,4); 
  pinMode(L_CPSR_A, OUTPUT);
  pinMode(L_CPSR_B, OUTPUT);
  pinMode(L_CPSR_PWM, OUTPUT);
  pinMode(CPSR_A, OUTPUT);
  pinMode(CPSR_B, OUTPUT);
  pinMode(CPSR_PWM, OUTPUT);
  pinMode(L_CPSL_A, OUTPUT);
  pinMode(L_CPSL_B, OUTPUT);
  pinMode(L_CPSL_PWM, OUTPUT);
  pinMode(CPSL_A, OUTPUT);
  pinMode(CPSL_B, OUTPUT);
  pinMode(CPSL_PWM, OUTPUT);
  pinMode(INV_PDLC, OUTPUT);
  pinMode(DL, OUTPUT);
//  pinMode(I_DL, OUTPUT);
  pinMode(DR, OUTPUT);
//  pinMode(I_DR, OUTPUT);
  pinMode(AMBIENT, OUTPUT); //driver led plafon light
//  pinMode(ReadL, OUTPUT); //driver led plafon light
//  pinMode(ReadR, OUTPUT); //driver led plafon light
  pinMode(INV_PDLC, OUTPUT);//driver inverter pdlc
  pinMode(MOTOR_A1_PIN, OUTPUT);
  pinMode(MOTOR_B1_PIN, OUTPUT);
  pinMode(MOTOR_A2_PIN, OUTPUT);
  pinMode(MOTOR_B2_PIN, OUTPUT);
  pinMode (STOP_CPSL_LOCK, INPUT); //stopper cpsl lock
  pinMode (STOP_CPSL_UNLOCK, INPUT); //stopper cpsl unlock
  pinMode (STOP_CPSL_DOWN, INPUT); //stopper cpsl down
  pinMode (STOP_CPSL_UP, INPUT); //stopper cpsl up
  pinMode (STOP_CPSR_LOCK, INPUT_PULLUP); //stopper cpsr lock 
  pinMode (STOP_CPSR_UNLOCK, INPUT_PULLUP); //stopper cpsr unlock
  pinMode (STOP_CPSR_DOWN, INPUT_PULLUP); //stopper cpsr down
  pinMode (STOP_CPSR_UP, INPUT_PULLUP); //stopper cpsr up
  pinMode(PWM_MOTOR_1, OUTPUT);
  pinMode(PWM_MOTOR_2, OUTPUT);
  pinMode(CURRENT_SEN_1, INPUT);
  pinMode(CURRENT_SEN_2, INPUT);  
  pinMode(CURRENT_SEN_3, INPUT);
  pinMode(CURRENT_SEN_4, INPUT);
  pinMode(ForceL, INPUT);
  pinMode(ForceR, INPUT);
//  pinMode(TrigR, OUTPUT);
//  pinMode(EchoR, INPUT);
  //pinMode(TrigL, OUTPUT);
  //pinMode(EchoL, INPUT);
  pinMode (CALL, OUTPUT);
  pinMode (TALK, OUTPUT);
  pinMode (DoorSW_L, INPUT_PULLUP);
  pinMode (DoorSW_R, INPUT_PULLUP);
  pinMode (BUZZER, OUTPUT);
  pinMode (IR, OUTPUT);
  
  lcd.begin(20,4);
  lcd.setCursor(0, 0);
  lcd.print("--ACS712-30B Test---");
  //Serial.println("--ACS712-30B Test---");  
  delay(10);
  lcd.clear();
}
