/*
 *
 * IRremote: IRsendMulti - demonstrates sending IR codes with IRsend with three parallel IR diodes.
 * An IR LED must be connected to Arduino PWM pin 3, 9 and 10:
 *
 * Tested on Arduino UNO board:
 * IRsend  - pin 3
 * IRsend1 - pin 9
 * IRsend2 - pin 10
 *
 * Original version of IRsend 
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 *
 * Idea of three parallel IR diodes
 * by khair-eddine 2015 Apr
 * https://github.com/khair-eddine
 *
 * Working library code for three parallel IR by
 * Tomas Stasiukaitis 2016
 * http://stasiukaitis.lt
 *
 */

#include <IRremote.h>

IRsend  irsend0;
IRsend1 irsend1;
IRsend2 irsend2;

void setup()
{
  Serial.begin(9600);
}

void loop() {
  if (Serial.read() != -1) {
    for (int i = 0; i < 3; i++) {
      irsend0.sendSony(0xa90, 12); // Sony TV power code
      delay(40);
      irsend1.sendSony(0xa90, 12); // Sony TV power code
      delay(40);
      irsend2.sendSony(0xa90, 12); // Sony TV power code
      delay(1500);
    }
  }
}
