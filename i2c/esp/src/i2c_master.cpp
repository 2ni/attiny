/*
 * I2C master to test slave on attiny167 (see attiny/src/i2c_slave.cpp)
 * Sends a value (as counter), which is returned by the slave
 */

#define DEBUG
#define SDA_PIN 4
#define SCL_PIN 5
#define ENABLE_I2C 14
#define LED 2
#define SLAVE_ADDR 0x50

#ifdef DEBUG
  #define D(x) Serial.print(x)
  #define DL(x) {Serial.println(x); /*client.publish(MQTT_TOPIC, "message");*/}
  #define DF(...) Serial.printf(__VA_ARGS__);
#else
  #define D(x)
  #define DL(x)
  #define DF(...)
#endif

#include <ESP8266WiFi.h>
#include <Wire.h>

byte counter=0;

/*
 * blink LED <amount> of times and on/off <duration> ms
 */
void blink(int amount=3, int duration=100) {
  for (byte i = 0; i < amount; ++i) {
    digitalWrite(LED, LOW); // turn LED on
    delay(duration);
    digitalWrite(LED, HIGH); // turn LED off
    if (amount > 1) delay(duration);
  }
}

void setup() {
  Serial.begin(115200);
  while (!Serial);

  pinMode(ENABLE_I2C, OUTPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(ENABLE_I2C, HIGH);

  DL("");
  DL("Booting.");
  blink();

  DL("I2C Scanner to scan for devices");
  Wire.begin(SDA_PIN, SCL_PIN);
}

void loop() {
  blink(1, 10);

  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(counter);
  Wire.endTransmission();

  Wire.requestFrom(SLAVE_ADDR, 1);
  DF("waiting.");

  int c=0;
  while (!Wire.available() && ++c < 5) {
    DF(".");
    delay(500);
  }

  if (c==5) {
    DF(" timeout\n");
  } else {
    byte byteReceived = Wire.read();
    DF(" received: %i\n", byteReceived);
    counter ++;
  }
  delay(1000);
}
