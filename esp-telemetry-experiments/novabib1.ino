#include <esp32_can.h>

// Defina as variáveis
byte envia[8] = {1, 21, 99}; 
byte recebe[8];

// Função para enviar dados
void get_envia() {
  int period = 100;
  unsigned long time_now = 0;
  time_now = millis();
  
  // Inicialize o pacote CAN
  CanPacket packet;
  packet.id = 0x05;
  packet.length = 8;
  memcpy(packet.data, envia, 8);
  
  // Envie o pacote CAN
  if (Can.send(packet)) {
    Serial.println("Pacote CAN enviado com sucesso!");
  } else {
    Serial.println("Erro ao enviar pacote CAN.");
  }

  while (millis() < time_now + period) {} // Potencialmente desnecessário
}

// Função para receber dados
void get_recebe() {
  long idcan;
  int value;
  int period = 10;
  unsigned long time_now = 0;
  time_now = millis();
  
  // Verifique se há um pacote CAN disponível
  if (Can.available()) {
    // Leitura do pacote CAN
    CanPacket packet;
    Can.read(packet);
    
    // Verifique se o pacote é vindo da UCE2
    if (packet.id == 0x01) {
      // Copie os dados do pacote para a variável recebe
      memcpy(recebe, packet.data, packet.length);
      
      // Imprima os dados recebidos
      Serial.println(String(recebe[0]) + "\t" + String(recebe[1]) + "\t" + String(recebe[2]));
    }
  }
}

void setup() {
  Serial.begin(9600);
  
  // Inicialize a interface CAN
  Can.begin(500E3, 4, 5);
  
  if (!Can.isInitialized()) {
    Serial.println("Erro ao inicializar CAN.");
    while (1);
  }

  Serial.println("Setup successful!");
}

void loop() {
  get_envia();
  get_recebe();
}