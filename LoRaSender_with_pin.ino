#include <SPI.h>
#include <LoRa.h>

int counter = 0;

void setup() {
  SerialUSB.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  while (!SerialUSB);

  SerialUSB.println("LoRa Sender");
  LoRa.setPins(5,3,2);
  if (!LoRa.begin(915E6)) {
    SerialUSB.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  SerialUSB.print("Sending packet: ");
  SerialUSB.println(counter);
  SerialUSB.print("' with RSSI ");
    SerialUSB.println(LoRa.packetRssi());

  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");xx
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;
}
