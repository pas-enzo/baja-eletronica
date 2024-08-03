#include "heltec.h"

#define BAND 915E6  // Define a frequência da banda

long lastSendTime = 0;        // Tempo do último envio
int interval = 1000;          // Intervalo entre os envios

byte recebe[32] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};

unsigned long lastTime = 0;

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(115200);
  while (!Serial);

  // Inicializa o Heltec com LoRa, Display desabilitado, Serial e PABOOST habilitados
  Heltec.begin(true /* DisplayEnable */, true /* LoRa Enable */, true /* Serial Enable */, true /* PABOOST Enable */, BAND /* long BAND */);
  LoRa.setTxPower(20, RF_PACONFIG_PASELECT_PABOOST);
  delay(1800);

  lastTime = millis();
  Serial.println("Setup OK!");
}

void loop() {
  //if ((millis() - lastTime) > interval) {
    //lastTime = millis();
    //LoRa.beginPacket();       // Inicia o pacote
    //LoRa.write(recebe, 32);   // Escreve o payload no pacote
    //LoRa.endPacket();         // Finaliza o pacote e envia
    Serial.println("Pacote LoRa enviado.");
  //}
}
