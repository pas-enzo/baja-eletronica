#include "heltec.h"
#define BAND    915E6
/*/________Buffers____________//
recebe[0] = Pressão da linha de freio dianteira
recebe[1] = Pressão do linha de freio traseira
recebe[2] = Velocidade dianteira
recebe[3] = Nível da bateria
recebe[4] = Temperatura CVT
recebe[5] = Rpm Dezena
recebe[6] = Rpm unidade
recebe[7] = Nível do combustível
recebe[8] = velocidade traseira
recebe[9] = Aceleração em x
recebe[10] = Aceleração em y
recebe[11] = Aceleração em z
recebe[12] = Giro em x
recebe[13] = Giro em y
recebe[14] = Giro em z
recebe[15] = Espaço livre
recebe[16] = TPMS1 temperatura
recebe[17] = TPMS1 pressão
recebe[18] = TPMS2 temperatura
recebe[19] = TPMS2 pressão
recebe[20] = TPMS3 temperatura
recebe[21] = TPMS3 pressão
recebe[22] = TPMS4 temperatura
recebe[23] = TPMS4 pressão
recebe[24] = Posição pedal acelerador
recebe[25] = Posição pedal freio
recebe[26] = Posição volante
recebe[27] = Botão 1 piloto
recebe[28] = Botão 2 piloto
recebe[29] = Botão 3 piloto
recebe[30] = GPS - Latitude
recebe[31] = GPS - Longitude
//______________________*/
String packSize = "--";
byte packet ;
byte gg[2] = {0}; // usar para receber valores da telemetria
byte recebe[32] = {0};
void cbk(int packetSize);
void setup()
{
  // delay(10000);
  Serial.begin(9600);
  // Serial.println("Iniciando...");
  Heltec.begin(false /*Habilita o Display*/, true /*Heltec.Heltec.Heltec.LoRa Disable*/, true /*Habilita debug Serial*/, true /*Habilita o PABOOST*/, BAND /*Frequência BAND*/);
  //LoRa.setTxPower(20, RF_PACONFIG_PASELECT_PABOOST);
  delay(1000);
  LoRa.receive(); // Habilita o rádio LoRa para receber dados 
  // Serial.println("LoRa iniciado com sucesso...");
}

void cbk(int packetSize) {
  packSize = String(packetSize,DEC);
  for (int i = 0; i < packetSize; i++) {
    recebe[i] = (byte) LoRa.read(); //Atribui um caractere por vez a váriavel packet 
    
  }
}

void loop()
{
  Serial.println("Chegou aqui");
  int packetSize = LoRa.parsePacket();
  if (packetSize) { //Verifica se há dados chegando via LoRa
    cbk(packetSize);
    for(int i=0; i < 32; i++){
    Serial.print(recebe[i]); //Imprime no monitor serial a temperatura
    Serial.print(";");
    }
    Serial.println();
  }
  delay(10);
}
