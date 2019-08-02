#include <SPI.h>
#include <LoRa.h>

void setup() {
  SerialUSB.begin(9600);
  while (!SerialUSB);

  SerialUSB.println("LoRa Receiver");
  LoRa.setPins(5,3,2);
  if (!LoRa.begin(915E6)) {
    SerialUSB.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    SerialUSB.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      SerialUSB.print((char)LoRa.read());
    }

    // print RSSI of packet
    SerialUSB.print("' with RSSI ");
    SerialUSB.println(LoRa.packetRssi());
  }
}
