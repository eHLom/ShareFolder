/*void CPSR_PushCallback(void *ptr){
  if (varCPSRPosition == "atas" && varCPSRStatus == "berhenti") {
    Read_Ultrasonic();
    Read_Force();
    if (FlexR == LOW && jarakR >= 50) {
      L_CPSR_Unlock();
      varCPSRStatus = "Buka kuncian";
      Serial.println (varCPSRStatus);
    }
    else if (FlexR == HIGH || jarakR <50) {
      Serial.println ("Ada orang atau ada barang dibawah kursi");
      buzzer_error();
      varCPSRStatus = "berhenti";
      Serial.println (varCPSRStatus);
      varCPSRPosition = "atas";
      Serial.print ("posisi CPSR = ");
      Serial.println (varCPSRPosition);
    }
  }
  if (varCPSRPosition == "Tidak sampai bawah" && varCPSRStatus == "Berhenti karena sensor arus")  {
    CPSR_Down();
    varCPSRStatus = "turun lagi";
  }
  
  if (varCPSRPosition == "bawah" && varCPSRStatus == "berhenti")  {
    CPSR_Up();
    varCPSRStatus = "CPSR naik";
    Serial.println (varCPSRStatus);
  }
  if (varCPSRPosition == "tidak sampai atas" && varCPSRStatus == "ketahan sensor arus pas naik")  {
    CPSR_Up();
    varCPSRStatus = "CPSR naik";
    Serial.println (varCPSRStatus);
  }
}
*/


void CPSR_OPEN_PopCallback(void *ptr){
  
  Serial.print ("varCPSRStatus ");
  Serial.println (varCPSRStatus);
  Serial.print ("varCPSRPosition ");
  Serial.println (varCPSRPosition);
  if (varCPSRPosition == "bawah" && varCPSRStatus == "berhenti")  {
    CPSR_Up();
    varCPSRStatus = "CPSR naik";
    Serial.println (varCPSRStatus);
  }
  if (varCPSRPosition == "tidak sampai atas" && varCPSRStatus == "ketahan sensor arus pas naik")  {
    CPSR_Up();
    varCPSRStatus = "CPSR naik";
    Serial.println (varCPSRStatus);
  }
}

void CPSR_CLOSE_PopCallback(void *ptr){
  Serial.print ("varCPSRStatus ");
  Serial.println (varCPSRStatus);
  Serial.print ("varCPSRPosition ");
  Serial.println (varCPSRPosition);
  if (varCPSRPosition == "atas" && varCPSRStatus == "berhenti") {
    //Read_Ultrasonic();
    //Read_Force();
    //if (FlexR == LOW && jarakR >= 50) {
    L_CPSR_Unlock();
    varCPSRStatus = "Buka kuncian";
    Serial.println (varCPSRStatus);
    //}
    /*else if (varCPSRPosition == "atas" && varCPSRStatus == "berhenti" && (FlexR == HIGH || jarakR <50)) {
      Serial.println ("Ada orang atau ada barang dibawah kursi");
      //buzzer_error();
      varCPSRStatus = "berhenti";
      Serial.println (varCPSRStatus);
      varCPSRPosition = "atas";
      Serial.print ("posisi CPSR = ");
      Serial.println (varCPSRPosition);
      buzzer_error();
    }*/
  }
  if (varCPSRPosition == "Tidak sampai bawah" && varCPSRStatus == "Berhenti karena sensor arus")  {
    CPSR_Down();
    varCPSRStatus = "turun lagi";
  }
}
