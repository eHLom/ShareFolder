void writeStringTV(String stringData) {
  for (int i = 0; i < stringData.length(); i++)
  {
    Serial1.write(stringData[i]);   // Push each char 1 by 1 on each loop pass  
  }
  Serial1.write(0xff); //We need to write the 3 ending bits to the Nextion as well
  Serial1.write(0xff); //it will tell the Nextion that this is the end of what we want to send.
  Serial1.write(0xff);
}

void writeStringPG(String stringData) {
  for (int i = 0; i < stringData.length(); i++)
  {
    Serial1.write(stringData[i]);   // Push each char 1 by 1 on each loop pass  
  }
  Serial1.write(0xff); //We need to write the 3 ending bits to the Nextion as well
  Serial1.write(0xff); //it will tell the Nextion that this is the end of what we want to send.
  Serial1.write(0xff);
}

void writeStringCPSR(String stringData) {
  for (int i = 0; i < stringData.length(); i++)
  {
    Serial1.write(stringData[i]);   // Push each char 1 by 1 on each loop pass  
  }
  Serial1.write(0xff); //We need to write the 3 ending bits to the Nextion as well
  Serial1.write(0xff); //it will tell the Nextion that this is the end of what we want to send.
  Serial1.write(0xff);
}

void writeStringCPSL(String stringData) {
  for (int i = 0; i < stringData.length(); i++)
  {
    Serial1.write(stringData[i]);   // Push each char 1 by 1 on each loop pass  
  }
  Serial1.write(0xff); //We need to write the 3 ending bits to the Nextion as well
  Serial1.write(0xff); //it will tell the Nextion that this is the end of what we want to send.
  Serial1.write(0xff);
}
