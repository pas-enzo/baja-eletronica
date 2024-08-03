#include <CAN.h>
byte envia[8] = {2, 42, 11}; // Ajustar valor máximo para byte
byte recebe[8];

void get_envia() {
  int period = 10;
  unsigned long time_now = 0;
  time_now = millis();
  long idcan;
  
  if (CAN.beginPacket(1)) { // Verifica se o pacote começou corretamente
    idcan = CAN.packetId();
    CAN.write(envia, 8);
    Serial.println(idcan);
    CAN.endPacket();
    Serial.println("Pacote enviado...");
  } else {
    Serial.println("Erro ao iniciar o pacote CAN.");
  }
  while(millis() < time_now + period) {} // Potencialmente desnecessário
}

void get_recebe(){
  long idcan;
  int value;
  int period = 100;
  unsigned long time_now = 0;
  time_now = millis();
  int packetSize = CAN.parsePacket();
  if (packetSize) {
    idcan = CAN.packetId(); 
    if (idcan == 5) { // Verifica se é vindo da UCE2      
      for (int i = 0; i < packetSize && i < 8; i++) {
        value = CAN.read();
        recebe[i] = value;
      }
      Serial.println(String(recebe[0]) + "\t" + String(recebe[1]) + "\t" + String(recebe[2]));
    }      
  }
}

void setup() {
  CAN.setPins(4, 5);
  Serial.begin(9600);
  if (!CAN.begin(500E3)) {
    Serial.println("Erro ao inicializar CAN.");
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
