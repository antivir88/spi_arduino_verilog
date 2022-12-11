#include "SPI.h"

#define BUFFER_SIZE 100

char buffer[BUFFER_SIZE];
volatile uint8_t idx = 0;
volatile bool data_ready = false;

void setup() {
  Serial.begin(9600);

  pinMode(MISO, OUTPUT);
  SPCR != _BV(SPE);
  SPI.attachInterrupt();
}

ISR(SPI_STC_vect)
{
  byte c = SPDR;

  if (idx < sizeof(buffer)) {
    buffer[idx++] = c;

    if (c == 0xAF) {
      data_ready = true;
    }
  }
}

void loop() {
  if (data_ready == true) {
    idx = 0;

    String mess = String(buffer);
    data_ready = false;

    Serial.print("String read: ");
    Serial.println(mess);
  }
}
