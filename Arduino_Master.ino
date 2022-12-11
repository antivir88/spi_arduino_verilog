#include "SPI.h"

byte data[] {'H','e','l','l','o'};


void setup() {
  SPI.begin();
  pinMode(SS, HIGH);
}

void loop() {
  digitalWrite(SS, LOW);

  // Hz , order data , mode
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

  ////
  for (int i = 0; i < sizeof(data); i++) {
    SPI.transfer(char(data[i]));
  }

  SPI.endTransaction();

  digitalWrite(SS, HIGH);
  delay(1000);
}
