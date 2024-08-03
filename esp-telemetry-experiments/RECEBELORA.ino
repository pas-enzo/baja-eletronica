#include "heltec.h"
#define BAND    915E6  //Escolha a frequência
String packSize = "--"; 
byte packet ;
byte recebe[8]= {0};
/* Protótipo da função */
void cbk(int packetSize);
/*
  Nome da função: LoRaDataPrint
  objetivo: imprime a temperatura e tamanho do pacote recebido no display.
*/
/*
  Nome da função: cbk
  recebe como parâmetos um inteiros (packetSize)
  objetivo: recebe a temperatura via LoRa e armazena na variável packet.
*/
void cbk(int packetSize) {
  packSize = String(packetSize,DEC);
  for (int i = 0; i < packetSize; i++) {
    recebe[i] = (byte) LoRa.read(); //Atribui um caractere por vez a váriavel packet 
    
  }
}
/******************* função principal (setup) *********************/
void setup()
{  
  Serial.begin(9600);
  Heltec.begin(false /*Habilita o Display*/, true /*Heltec.Heltec.Heltec.LoRa Disable*/, true /*Habilita debug Serial*/, true /*Habilita o PABOOST*/, BAND /*Frequência BAND*/);
//  LoRa.setTxPower(20, RF_PACONFIG_PASELECT_PABOOST);
  delay(1000);
  LoRa.receive(); // Habilita o rádio LoRa para receber dados
}
/******************* função em loop (loop) *********************/
void loop()
{
  int packetSize = LoRa.parsePacket();
  if (packetSize) { //Verifica se há dados chegando via LoRa
    cbk(packetSize);
    for(int i=0; i <8; i++){
    Serial.print(recebe[i]); //Imprime no monitor serial a temperatura
    Serial.print(";");
    }
    Serial.println();
  }
  delay(10);
} 
