#include <Arduino.h>
//#include <DigiKeyboard.h>
//#include <DigiCDC.h>

#define LED 1

void setup() {
  pinMode(LED, OUTPUT);

  //SerialUSB().begin();
}

void loop() {
  //SerialUSB.println(F("TEST!"));

  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
  //DigiKeyboard.println("Hello Digispark!");
  //DigiKeyboard.delay(1000);
}
