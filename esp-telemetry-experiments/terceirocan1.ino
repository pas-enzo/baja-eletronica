#include <CAN.h>

byte envia[8] = {1, 21, 255, 4, 4, 4, 4, 4}; 
byte envia2[8] = {2, 22, 0, 9, 9, 9, 9, 9}; 
byte recebe[8];
byte recebe2[8];

short int inversor = 0;

void new_value_test() {
  if(envia[1] == 255) envia[1] = 0;
  if(envia2[1] == 255) envia2[1] = 0;

  envia[1]++;
  envia2[1]++;
}

void get_envia() {
  int period = 150;
  unsigned long time_now = millis();
  if (CAN.beginPacket(0x13)) {
    CAN.write(envia, 8);
    CAN.endPacket();
  } else {
    Serial.println("Erro ao iniciar o pacote CAN.");
  }

  if (CAN.beginPacket(0x14)) {
    CAN.write(envia2, 8);
    CAN.endPacket();
  } else {
    Serial.println("Erro ao iniciar o pacote CAN.");
  }

  // !inversor;
  // Serial.print("Inv: ");
  // Serial.println(inversor);
  //while (millis() < time_now + period) {}
}

void get_recebe() {
  int packetSize = CAN.parsePacket();
  if (packetSize) {
    long idcan = CAN.packetId(); 
    if (idcan == 0x11) { 
      for (int i = 0; i < packetSize && i < 8; i++) {
        recebe[i] = CAN.read();
      }
      Serial.println(String(recebe[0]) + "\t" + String(recebe[1]) + "\t" + String(recebe[2]) + "\t" + String(recebe[3]) + "\t" + String(recebe[4]) + "\t" + String(recebe[5]) + "\t" + String(recebe[6]) + "\t" + String(recebe[7]));
    } else if (idcan == 0x12) {
      for (int i = 0; i < packetSize && i < 8; i++) {
        recebe2[i] = CAN.read();
      }
      Serial.println(String(recebe2[0]) + "\t" + String(recebe2[1]) + "\t" + String(recebe2[2]) + "\t" + String(recebe2[3]) + "\t" + String(recebe2[4]) + "\t" + String(recebe2[5]) + "\t" + String(recebe2[6]) + "\t" + String(recebe2[7]));
    }
  }
}

void setup() {
  Serial.begin(9600);
  CAN.setPins(4, 5);
  if (!CAN.begin(500E3)) {
    Serial.println("Erro ao inicializar CAN.");
    while (1);
  }
  Serial.println("Setup successful!");
}

void loop() {
  get_envia();
  get_recebe();
  //new_value_test();
}
