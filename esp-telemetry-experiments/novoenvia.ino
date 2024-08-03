#include "heltec.h"
#define BAND 915E6  // Frequência de operação

byte Envia[8] = {3};

void sendPacket() {
  LoRa.beginPacket();
  LoRa.write(Envia, 8);
  LoRa.endPacket();
}

void setup() {
  Serial.begin(115200);
  Heltec.begin(false, true, true, true, BAND);
  LoRa.setTxPower(20, RF_PACONFIG_PASELECT_PABOOST);
  delay(1000);
}

void loop() {
  // Simulação de leitura de dados para enviar
  for (int i = 0; i < 8; i++) {
    Envia[i] = i * 10; // Exemplo de dados
  }
  sendPacket(); // Envia o pacote
  delay(1000); // Envia a cada segundo
}

