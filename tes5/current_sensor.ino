void current_sensor() {
  float AcsValueTV = 0.0, Samples = 0.0, AvgAcs = 0.0, AcsValueF = 0.0,
        AcsValuePG = 0.0, Samples1 = 0.0, AvgAcs1 = 0.0, AcsValueF1 = 0.0,
        AcsValueCPSR = 0.0, Samples2 = 0.0, AvgAcs2 = 0.0, AcsValueF2 = 0.0,
        AcsValueCPSL = 0.0, Samples3 = 0.0, AvgAcs3 = 0.0, AcsValueF3 = 0.0;

  for (int x = 0; x < 150; x++) {
    AcsValueTV = analogRead(CURRENT_SEN_1);
    AcsValuePG = analogRead(CURRENT_SEN_2);
    AcsValueCPSR = analogRead(CURRENT_SEN_3);
    AcsValueCPSL = analogRead(CURRENT_SEN_4);
    Samples = Samples + AcsValueTV;
    Samples1 = Samples1 + AcsValuePG;
    Samples2 = Samples2 + AcsValueCPSR;
    Samples3 = Samples3 + AcsValueCPSL;
    delay (1);
  }
  AvgAcs = Samples / 150.0;
  AvgAcs1 = Samples1 / 150.0;
  AvgAcs2 = Samples2 / 150.0;
  AvgAcs3 = Samples3 / 150.0;

  double Vcc, vcc;
  Vcc = readVcc() / 1000.0;
  vcc = Vcc / 2.0;



  // TV
  AcsValueF = (vcc - (AvgAcs * (Vcc / 1024.0)) ) / 0.100;
  /*lcd.setCursor(0, 0);
  lcd.print("M--TV : ");
  lcd.setCursor(9, 0);
  lcd.print(AcsValueF, 2);
  lcd.setCursor(16, 0);
  lcd.print("Amp");
  Serial.print("Motor TV     = ");
    Serial.print(AcsValueF,2);
    Serial.print(" Ampere");
    Serial.println(); */
  
  //KACA
  AcsValueF1 = (vcc - (AvgAcs1 * (Vcc / 1024.0)) ) / 0.100;
  /*lcd.setCursor(0, 1);
  lcd.print("M--PG : ");
  lcd.setCursor(9, 1);
  lcd.print(AcsValueF1, 2);
  lcd.setCursor(16, 1);
  lcd.print("Amp");
  Serial.print("Motor PG      = ");
    Serial.print(AcsValueF1);
    Serial.print(" Ampere");
    Serial.println();
  */
  //CPSR
  AcsValueF2 = (vcc - (AvgAcs2 * (Vcc / 1024.0)) ) / 0.100;
  /*lcd.setCursor(0, 2);
  lcd.print("M--CPSR : ");
  lcd.setCursor(9, 2);
  lcd.print(AcsValueF2, 2);
  lcd.setCursor(16, 2);
  lcd.print("Amp");
  Serial.print("Motor CPSR      = ");
    Serial.print(AcsValueF2,2);
    Serial.print(" Ampere");
    Serial.println();
  */
  //CPSL
  AcsValueF3 = (vcc - (AvgAcs3 * (Vcc / 1024.0)) ) / 0.100;
  /*lcd.setCursor(0, 3);
  lcd.print("M--CPSL : ");
  lcd.setCursor(9, 3);
  lcd.print(AcsValueF3, 2);
  lcd.setCursor(16, 3);
  lcd.print("Amp");
  Serial.print("Motor CPSL      = ");
    Serial.print(AcsValueF3,2);
    Serial.print(" Ampere");
    Serial.println();
  */

  
  // TV Stop atas
  if  (varTVStatus == "naik" &&  AcsValueF <limTVup)  {
    TV_Stop();
    varTVStatus = "berhenti";
    varTVPosition = "atas";
    // send to TFT
    String infoTV = "";
    delay (1);
    infoTV = "TV.txt=";
    infoTV.concat("\"TV_Up\"");
    writeStringTV(infoTV);
  }
  // TV Stop bawah
  if  ((VAR_STOP_TV == HIGH && varTVStatus == "turun")  ||  (AcsValueF >limTVdown))  {
    TV_Stop();
    varTVStatus = "berhenti";
    varTVPosition = "bawah";
    //send to TFT
    String infoTV = "";
    delay (1);
    infoTV = "TV.txt=";
    infoTV.concat("\"TV_Down\"");
    writeStringTV(infoTV);
  }

  // Kaca Stop atas
  if  (varPGStatus == "naik" &&  AcsValueF1 < limPGup)  {
    varPGStatus = "berhenti";
    PG_Stop();
    varPGPosition = "atas";
    //send to TFT
    String infoPG = "";
    delay (1);
    infoPG = "PG.txt=";
    infoPG.concat("\"PG_Up\"");
    writeStringPG(infoPG);
  }
  // Kaca Stop bawah
  if  ((VAR_STOP_PG == HIGH && varPGStatus == "turun")  ||  (AcsValueF1 >limPGdown))  {
    varPGStatus = "berhenti";
    PG_Stop();
    varPGPosition = "bawah";
    //send to TFT
    String infoPG = "";
    delay (1);
    infoPG = "PG.txt=";
    infoPG.concat("\"PG_Down\"");
    writeStringPG(infoPG);
  }
  
  
  // sequence naik CPSR
  // CPSR Stop
  // kalau terhenti oleh sensor arus
  if (AcsValueF2 < limCPSRup  && varCPSRStatus == "CPSR naik") {
    Read_Stopper();
    //Print_Stopper();
    if (VAR1_STOP_CPSR_UP == 0) {
      CPSR_Stop();
      varCPSRStatus = "ketahan sensor arus pas naik";
      Serial.println (varCPSRStatus);
      varCPSRPosition = "tidak sampai atas";
      Serial.print ("posisi CPSR = ");
      Serial.println (varCPSRPosition); 
      buzzer_error();
      //send to TFT
      String infoCPSR = "";
      delay (1);
      infoCPSR = "CPSR.txt=";
      infoCPSR.concat("\"CPSR_Down\"");
      writeStringCPSR(infoCPSR);
      }
  }
  if  (VAR1_STOP_CPSR_UP == 1 && varCPSRPosition == "tidak sampai atas"){
    CPSR_Stop();
    varCPSRStatus = "Kena Stopper";
    Serial.println (varCPSRStatus);
    varCPSRStatus = "berhenti";
    Serial.println (varCPSRStatus);
    varCPSRPosition = "atas";
    Serial.print ("posisi CPSR = ");
    Serial.println (varCPSRPosition);
    String infoCPSR = "";
    delay (1);
    infoCPSR = "CPSR.txt=";
    infoCPSR.concat("\"CPSR_Up\"");
    writeStringCPSR(infoCPSR);
  }
  if  (VAR1_STOP_CPSR_UP == 1 && varCPSRStatus == "CPSR naik"){
    CPSR_Stop();
    varCPSRStatus = "Kena Stopper";
    Serial.println (varCPSRStatus);
    varCPSRStatus = "berhenti";
    Serial.println (varCPSRStatus);
    varCPSRPosition = "atas";
    Serial.print ("posisi CPSR = ");
    Serial.println (varCPSRPosition);
    String infoCPSR = "";
    delay (1);
    infoCPSR = "CPSR.txt=";
    infoCPSR.concat("\"CPSR_Up\"");
    writeStringCPSR(infoCPSR);
  }
  
  
  // sequence turun CPSR
  // L_CPSR Stop, udah kena stopper buka kuncian
  if  (VAR1_STOP_CPSR_UNLOCK == 1 && varCPSRStatus == "Buka kuncian")  {
    L_CPSR_Stop();
    varCPSRStatus = "Udah ga ngunci";
    Serial.println (varCPSRStatus);
    // CPSR turun
    CPSR_Down();
    varCPSRStatus = "CPSR turun";
    Serial.println (varCPSRStatus);
  }
  // kena stopper bawah CPS kanan
  if  (VAR1_STOP_CPSR_DOWN == 1 && varCPSRStatus == "CPSR turun") {
    CPSR_Stop();
    varCPSRStatus = "Kena stopper bawah CPS kanan";
    Serial.println (varCPSRStatus);
    // motor kuncian ngunci
    L_CPSR_Lock();
    varCPSRStatus = "Kunci lagi";
    Serial.println (varCPSRStatus);
  }

  // kena stopper tutup kuncian CPS kanan
  if  (VAR1_STOP_CPSR_LOCK == 1 && varCPSRStatus == "Kunci lagi")  {
    L_CPSR_Stop();
    varCPSRStatus = "Udah ngunci";
    Serial.println (varCPSRStatus);
    varCPSRStatus = "berhenti";
    varCPSRPosition = "bawah";
    Serial.println (varCPSRStatus);
    Serial.print ("posisi CPSR = ");
    Serial.println (varCPSRPosition);
    String infoCPSR = "";
    delay (1);
    infoCPSR = "CPSR.txt=";
    infoCPSR.concat("\"CPSR_Down\"");
    writeStringCPSR(infoCPSR);
  }
  
  // ketahan oleh sensor arus
  if (AcsValueF2 > limCPSRdown && varCPSRStatus == "CPSR turun")  {
    CPSR_Stop();
    varCPSRStatus = "Berhenti karena sensor arus";
    Serial.println (varCPSRStatus);
    varCPSRPosition = "Tidak sampai bawah";
    Serial.print ("posisi CPSR = ");
    Serial.println (varCPSRPosition);
    buzzer_error();
    String infoCPSR = "";
    delay (1);
    infoCPSR = "CPSR.txt=";
    infoCPSR.concat("\"CPSR_Up\"");
    writeStringCPSR(infoCPSR);
  }
  // setelah ketahan oleh sensor arus, lalu kena stopper bawah 
  if (VAR1_STOP_CPSR_DOWN == 1 && varCPSRStatus == "turun lagi")  {
    CPSR_Stop();
    L_CPSR_Lock();
    varCPSRStatus = "Kunci lagi";
    Serial.println(varCPSRStatus);
    varCPSRPosition = "bawah";
    Serial.print ("posisi CPSR = ");
    Serial.println (varCPSRPosition);
  }
  // setelah ketahan oleh sensor arus, lalu ketahan oleh sensor arus lagi
  if (AcsValueF2 > limCPSRdown && varCPSRStatus == "turun lagi")  {
    CPSR_Stop();
    varCPSRStatus = "Berhenti karena sensor arus";
    Serial.println (varCPSRStatus);
    varCPSRPosition = "Tidak sampai bawah";
    Serial.print ("posisi CPSR = ");
    Serial.println (varCPSRPosition);
    buzzer_error();
    String infoCPSR = "";
    delay (1);
    infoCPSR = "CPSR.txt=";
    infoCPSR.concat("\"CPSR_Up\"");
    writeStringCPSR(infoCPSR);
  }
  
  
  // CPSL Stop
  // sequence naik CPSL
  //Read_Stopper();
  if (AcsValueF3 < limCPSLup  && varCPSLStatus == "CPSL naik") {
    Read_Stopper();
    if (VAR1_STOP_CPSL_UP == 0) {
      CPSL_Stop();
      varCPSLStatus = "ketahan sensor arus pas naik";
      Serial.println (varCPSLStatus);
      varCPSLPosition = "tidak sampai atas";
      Serial.print ("posisi CPSL = ");
      Serial.println (varCPSLPosition); 
      buzzer_error();
      String infoCPSL = "";
      delay (1);
      infoCPSL = "CPSL.txt=";
      infoCPSL.concat("\"CPSL_Down\"");
      writeStringCPSL(infoCPSL);
    }
  }
  
  //Read_Stopper();
  if  (VAR1_STOP_CPSL_UP == 1 && varCPSLPosition == "tidak sampai atas"){
    CPSL_Stop();
    varCPSLStatus = "Kena Stopper";
    Serial.println (varCPSLStatus);
    varCPSLStatus = "berhenti";
    Serial.println (varCPSLStatus);
    varCPSLPosition = "atas";
    Serial.print ("posisi CPSL = ");
    Serial.println (varCPSLPosition);
    String infoCPSL = "";
    delay (1);
    infoCPSL = "CPSL.txt=";
    infoCPSL.concat("\"CPSL_Up\"");
    writeStringCPSL(infoCPSL);
  }

if  (VAR1_STOP_CPSL_UP == 1 && varCPSLStatus == "CPSL naik"){
    CPSL_Stop();
    varCPSLStatus = "Kena Stopper";
    Serial.println (varCPSLStatus);
    varCPSLStatus = "berhenti";
    Serial.println (varCPSLStatus);
    varCPSLPosition = "atas";
    Serial.print ("posisi CPSL = ");
    Serial.println (varCPSLPosition);
    String infoCPSL = "";
    delay (1);
    infoCPSL = "CPSL.txt=";
    infoCPSL.concat("\"CPSL_Up\"");
    writeStringCPSL(infoCPSL);
  }
  
  
  // sequence turun CPSL
  // L_CPSL Stop, udah kena stopper buka kuncian
  if  (VAR1_STOP_CPSL_UNLOCK == 1 && varCPSLStatus == "Buka kuncian")  {
    L_CPSL_Stop();
    varCPSLStatus = "Udah ga ngunci";
    Serial.println (varCPSLStatus);
    // CPSL turun
    CPSL_Down();
    varCPSLStatus = "CPSL turun";
    Serial.println (varCPSLStatus);
  }
  // kena stopper bawah CPS kanan
  if  (VAR1_STOP_CPSL_DOWN == 1 && varCPSLStatus == "CPSL turun") {
    CPSL_Stop();
    varCPSLStatus = "Kena stopper bawah CPS kanan";
    Serial.println (varCPSLStatus);
    // motor kuncian ngunci
    L_CPSL_Lock();
    varCPSLStatus = "Kunci lagi";
    Serial.println (varCPSLStatus);
  }

  // kena stopper tutup kuncian CPS kanan
  if  (VAR1_STOP_CPSL_LOCK == 1 && varCPSLStatus == "Kunci lagi")  {
    L_CPSL_Stop();
    varCPSLStatus = "Udah ngunci";
    Serial.println (varCPSLStatus);
    varCPSLStatus = "berhenti";
    varCPSLPosition = "bawah";
    Serial.println (varCPSLStatus);
    Serial.print ("posisi CPSL = ");
    Serial.println (varCPSLPosition);
    String infoCPSL = "";
    delay (1);
    infoCPSL = "CPSL.txt=";
    infoCPSL.concat("\"CPSL_Down\"");
    writeStringCPSL(infoCPSL);
  }
  
  // ketahan oleh sensor arus
  if (AcsValueF3 > limCPSLdown && varCPSLStatus == "CPSL turun")  {
    CPSL_Stop();
    varCPSLStatus = "Berhenti karena sensor arus";
    Serial.println (varCPSLStatus);
    varCPSLPosition = "Tidak sampai bawah";
    Serial.print ("posisi CPSL = ");
    Serial.println (varCPSLPosition);
    buzzer_error();
    String infoCPSL = "";
    delay (1);
    infoCPSL = "CPSL.txt=";
    infoCPSL.concat("\"CPSL_Up\"");
    writeStringCPSL(infoCPSL);
  }
  // setelah ketahan oleh sensor arus, lalu kena stopper bawah 
  if (VAR1_STOP_CPSL_DOWN == 1 && varCPSLStatus == "turun lagi")  {
    CPSL_Stop();
    L_CPSL_Lock();
    varCPSLStatus = "Kunci lagi";
    Serial.println(varCPSLStatus);
    varCPSLPosition = "bawah";
    Serial.print ("posisi CPSL = ");
    Serial.println (varCPSLPosition);
    String infoCPSL = "";
    delay (1);
    infoCPSL = "CPSL.txt=";
    infoCPSL.concat("\"CPSL_Down\"");
    writeStringCPSL(infoCPSL);
  }
  // setelah ketahan oleh sensor arus, lalu ketahan oleh sensor arus lagi
  if (AcsValueF3 > limCPSLdown && varCPSLStatus == "turun lagi")  {
    CPSL_Stop();
    varCPSLStatus = "Berhenti karena sensor arus";
    Serial.println (varCPSLStatus);
    varCPSLPosition = "Tidak sampai bawah";
    Serial.print ("posisi CPSL = ");
    Serial.println (varCPSLPosition);
    buzzer_error();
    String infoCPSL = "";
    delay (1);
    infoCPSL = "CPSL.txt=";
    infoCPSL.concat("\"CPSL_Up\"");
    writeStringCPSL(infoCPSL);

  }
}
