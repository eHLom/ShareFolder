void Ambient_PopCallback(void *ptr)    {
//  Serial2.write (0);
//  Serial.println ("0");
  if(varAmbient =="mati") {
    for (int i = 255; i >= 0; i--)  {
      analogWrite (AMBIENT, i);
      delay (7);
    }
  }
  else if(varAmbient=="nyala")  {
    for (int i = 0; i <= 255; i++)  {
      analogWrite (AMBIENT, i);
      delay (7);
    }
  }
}

void Ambient_PushCallback(void *ptr)  {
//  Serial2.write (1);
//  Serial.println ("1");
  if(varAmbient== "mati") {
    varAmbient="nyala";
  }
  else if(varAmbient=="nyala")  {
    varAmbient= "mati";
  }
  Serial.println (varAmbient); 
}

void switch_door()  {
  door_switch_R = digitalRead (DoorSW_R);
  door_switch_L = digitalRead (DoorSW_L);
  if (door_switch_L == HIGH)  {
    varDoorL = "buka";
    varPintu = 1;
    varAmbient="nyala";
    analogWrite (AMBIENT, 255);
    Serial.print ("status pintu L = ");
    Serial.println (varDoorL);
  }
  else if (door_switch_L == LOW)  {
    varDoorL = "tutup";
    if (varPintu == 1)  {
      analogWrite (AMBIENT, 255);
      varPintu = 0;
      varAmbient="nyala";
      Serial.print ("status pintu L = ");
      Serial.println (varDoorL);
    }
  }
  else if (door_switch_R == HIGH)  {
    varDoorR = "buka";
    varPintu = 1;
    analogWrite (AMBIENT, 255);
    varAmbient="nyala";
    Serial.print ("status pintu R = ");
    Serial.println (varDoorR);
  }
  else if (door_switch_R == LOW)  {
    varDoorR = "tutup";
    if (varPintu == 1)  {
      analogWrite (AMBIENT, 255);
      varPintu = 0;
      varAmbient="nyala";
    }
    Serial.print ("status pintu R = ");
    Serial.println (varDoorR);
  }
}
