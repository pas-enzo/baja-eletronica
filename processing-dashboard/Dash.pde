// Arquivo principal para carregar a dashboard com inspiração do Iotti - by Enzimas

import processing.serial.*;                                                       // biblioteca para comunicação serial

PFont fonte;

Serial myPort;                                                                    // nova instância da classe serial "myPort"

int selecionador = 0;                                                             // variável para fazer o controle de janelas

void setup () {

  size(1440, 900);
  frameRate(60);
  
  fonte = loadFont("Venera500-48.vlw");
  textFont(fonte);
  
  setupLoadImages();
}

void draw (){
  
  if(selecionador == 0) {
    push();
    inicio();
    pop();
  }
  
  if(selecionador == 1) {
    push();
    mapa();
    pop();
  }
  
  if(selecionador == 2) {
    push();
    graf();
    pop();
  }
  
  if(selecionador == 3) {
    push();
    raster();
    pop();
  }
}

void mouseClicked () {
 
  if ((mouseX >= 0 & mouseX <= 400) & (mouseY >=0 & mouseY <= 150)) selecionador = 0;
  
  if ((mouseX >= 401 & mouseX <= 800) & (mouseY >=0 & mouseY <= 150)) selecionador = 1;
  
  if ((mouseX >= 801 & mouseX <= 1200) & (mouseY >=0 & mouseY <= 150)) selecionador = 2;
  
  if ((mouseX >= 1201 & mouseX <= 1440) & (mouseY >=0 & mouseY <= 150)) selecionador = 3;
  
  if ((mouseX >= 20 & mouseX <= 205) & (mouseY >= 350 & mouseY <= 440) & selecionador == 0) {
    if (alerta_telemetria == 0) alerta_telemetria = 1;
    else alerta_telemetria = 0;
  }
}
