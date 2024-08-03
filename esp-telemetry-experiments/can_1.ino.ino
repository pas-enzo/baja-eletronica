#include <CAN.h>

byte envia[8] = {1, 21, 99}; 
byte recebe[8];

void setup() {
  CAN.setPins(4, 5);
  Serial.begin(9600);

  Serial.println("Starting setup...");
  if (!CAN.begin(500E3)) {
    Serial.println("CAN Initializing failure.");
    while (1);
  }

  Serial.println("Setup successful!");
}

void loop() {
  get_envia();
  get_recebe();
  //Serial.println("Loop pass...");
  Serial.println(String(recebe[0]) + "\t" + String(recebe[1]) + "\t" + String(recebe[2]));
}

void get_envia() {
  int period = 100;
  unsigned long time_now = 0;
  time_now = millis();
  long idcan;
  
  if ((CAN.beginPacket(5)) > 0) { // Verifica se o pacote começou corretamente
    idcan = CAN.packetId();
    Serial.println(idcan);
    CAN.write(envia, 8);
    CAN.endPacket();
    Serial.println("Pacote enviado...");
  } else {
    Serial.println("Erro ao iniciar o pacote CAN.");
  }

  while (millis() < time_now + period) {} // Potencialmente desnecessário
}

void get_recebe() {
  long idcan;
  int value;
  int period = 100;
  unsigned long time_now = 0;
  time_now = millis();
  int packetSize = CAN.parsePacket();

  //Serial.println("Get recebe init.");

  //Serial.println(packetSize);
  
  if (packetSize) { // Se temos um pacote
    idcan = CAN.packetId(); 

    //Serial.println("Idcan = " + String(idcan));

    if (idcan == 1) { // Verifica se é vindo da UCE2      
      for (int i = 0; i < packetSize && i < 8; i++) { // Limita a leitura ao tamanho do buffer
        value = CAN.read();
        recebe[i] = value;
      }
      Serial.println(String(recebe[0]) + "\t" + String(recebe[1]) + "\t" + String(recebe[2]));
    }
  }
}
