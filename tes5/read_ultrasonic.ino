void Read_Ultrasonic  ()  {
  jarakR = sensorR.getDistance();
  Serial.print ("\n Jarak R: ");
  Serial.print (jarakR);
  Serial.println ("cm");
  delay (5);

  jarakL = sensorL.getDistance();
  Serial.print ("\n Jarak L: ");
  Serial.print (jarakL);
  Serial.println ("cm");
  delay (5);

}
