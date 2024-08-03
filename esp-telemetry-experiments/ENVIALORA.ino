//inclusão de bibliotecas
#include "heltec.h"
//#include <CAN.h>
#define BAND    915E6  //Escolha a frequência
byte Envia[8] = {3};
/* Protótipo da função */
    
void sendPacket()
{
  LoRa.beginPacket();
  LoRa.write(Envia,8);  
  LoRa.endPacket();
}
/******************* função principal (setup) *********************/
void setup()
{
  Serial1.begin(115200, SERIAL_8N1, 16, 17);
  Heltec.begin(false /*Habilita o Display*/, true /*Heltec.Heltec.Heltec.LoRa Disable*/, true /*Habilita debug Serial*/, true /*Habilita o PABOOST*/, BAND /*Frequência BAND*/);
  //LoRa.setTxPower(20, RF_PACONFIG_PASELECT_PABOOST);
  delay(1000);
}
/******************* função em loop (loop) *********************/
void loop()
{
  
  Serial.read(Envia,32);
  sendPacket(); //Envia temperatura
}

/* codigo do gpt
#include <heltec.h>

#define BAND    915E6  // Frequência de operação (915 MHz)
#define PABOOST true   // Ativar amplificador de potência PA_BOOST

void setup() {
  Serial.begin(115200);

  if (!LoRa.begin(BAND, PABOOST)) {
    Serial.println("Inicialização do LoRa falhou!");
    while (1);
  }

  LoRa.setTxPower(20);  // Define a potência de transmissão (dBm)
}

void sendList(int list[], int size) {
  LoRa.beginPacket();
  
  for (int i = 0; i < size; i++) {
    LoRa.write(list[i]);
  }
  
  LoRa.endPacket();
}

void loop() {
  const char* message = "Hello, radio world!";
  
  int myList[32];  // Lista de inteiros
  for (int i = 0; i < 32; i++) {
    myList[i] = i * 2;  // Preenchendo a lista com valores de exemplo
  }
  
  sendList(myList, sizeof(myList) / sizeof(myList[0]));  // Envia a lista

  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();
  
  Serial.println("Mensagem enviada!");

  delay(5000);
}

*/

/* codigo secundario de envio
#include <heltec.h>

#define BAND    915E6  // Frequência de operação (915 MHz)
#define PABOOST true   // Ativar amplificador de potência PA_BOOST

void setup() {
  Serial.begin(115200);

  if (!LoRa.begin(BAND, PABOOST)) {
    Serial.println("Inicialização do LoRa falhou!");
    while (1);
  }

  LoRa.setTxPower(20);  // Define a potência de transmissão (dBm)
}

void loop() {
  int myList[32];  // Lista de inteiros
  for (int i = 0; i < 32; i++) {
    myList[i] = i * 2;  // Preenchendo a lista com valores de exemplo
  }
  
  LoRa.beginPacket();
  
  // Enviando a lista
  for (int i = 0; i < sizeof(myList) / sizeof(myList[0]); i++) {
    LoRa.write(myList[i]);
  }
  
  LoRa.endPacket();
  
  Serial.println("Lista enviada!");

  delay(5000);
}

*/