void CPSL_OPEN_PopCallback(void *ptr){
  
  Serial.print ("varCPSLStatus ");
  Serial.println (varCPSLStatus);
  Serial.print ("varCPSLPosition ");
  Serial.println (varCPSLPosition);
  if (varCPSLPosition == "bawah" && varCPSLStatus == "berhenti")  {
    CPSL_Up();
    varCPSLStatus = "CPSL naik";
    Serial.println (varCPSLStatus);
  }
  if (varCPSLPosition == "tidak sampai atas" && varCPSLStatus == "ketahan sensor arus pas naik")  {
    CPSL_Up();
    varCPSLStatus = "CPSL naik";
    Serial.println (varCPSLStatus);
  }
}

void CPSL_CLOSE_PopCallback(void *ptr){
  Serial.print ("varCPSLStatus ");
  Serial.println (varCPSLStatus);
  Serial.print ("varCPSLPosition ");
  Serial.println (varCPSLPosition);
  if (varCPSLPosition == "atas" && varCPSLStatus == "berhenti") {
    //Read_Ultrasonic();
    //Read_Force();
    //if (FlexL == LOW && jarakL >= 50) {
    L_CPSL_Unlock();
    varCPSLStatus = "Buka kuncian";
    Serial.println (varCPSLStatus);
    //}
    /*else if (varCPSLPosition == "atas" && varCPSLStatus == "berhenti" && (FlexL == HIGH || jarakL <50)) {
      Serial.println ("Ada orang atau ada barang dibawah kursi");
      //buzzer_error();
      varCPSLStatus = "berhenti";
      Serial.println (varCPSLStatus);
      varCPSLPosition = "atas";
      Serial.print ("posisi CPSL = ");
      Serial.println (varCPSLPosition);
      buzzer_error();
    }*/
  }
  if (varCPSLPosition == "Tidak sampai bawah" && varCPSLStatus == "Berhenti karena sensor arus")  {
    CPSL_Down();
    varCPSLStatus = "turun lagi";
  }
}
