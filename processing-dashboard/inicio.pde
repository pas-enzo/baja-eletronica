// Função referente à aba PAINEL na dashboard - by Enzimas

void inicio () {
  
  // carrega a imagem "PAINEL"
  image(fundo1,0,0);
  
  // formatação de texto
  textSize(40);
  fill(0);
  textAlign(CENTER);
  
  // RPM
  if (rpm <= 1000) image(rpm_img1, 270, 220);
  if (rpm > 1000 & rpm <= 2000) image(rpm_img5, 270, 220);
  if (rpm > 2000 & rpm <= 3000) image(rpm_img7, 270, 220);
  if (rpm > 3000) image(rpm_img8, 270, 220);
  text(rpm, 330, 300);
  
  // Velocidade
  textSize(80);
  text(velocidade, 690, 270);
  
  // Angulação do volante
  textSize(60);
  text(posicao_volante, 480, 470);
    
  if (posicao_volante >= -15 & posicao_volante <= 15) {
    image(volante, 260, 365);
  }
  
  if (posicao_volante > 15 & posicao_volante <= 45) { 
    volante_r45.resize(190, 0);
    image(volante_r45, 230, 335);
  }
  
  if (posicao_volante > 45) { 
    volante_r90.resize(130, 0);
    image(volante_r90, 260, 365);
  }
  
  if (posicao_volante < -15 & posicao_volante >= -45) { 
    volante_l45.resize(190, 0);
    image(volante_l45, 230, 335);
  }
  
  if (posicao_volante < -45) { 
    volante_l90.resize(130, 0);
    image(volante_l90, 260, 365);
  }
  
  // Forças G
  textSize(20);
  text(forca_g_x, 750, 390);
  text(forca_g_y, 750, 450);
  marcador.resize(30, 0);
  image(marcador, 870 + (forca_g_x * 200), 417 + (forca_g_y * 200));
  
  // Bateria
  if(bateria <= 25) {
    bat_img1.resize(115, 0);
    image(bat_img1, 772, 562);
  }
  
  if(bateria > 25 & bateria <= 50) {
    bat_img2.resize(115, 0);
    image(bat_img2, 772, 562);
  }
  
  if(bateria > 50 & bateria <= 75) {
    bat_img3.resize(115, 0);
    image(bat_img3, 772, 562);
  }
  
  if(bateria > 75) {
    bat_img4.resize(115, 0);
    image(bat_img4, 772, 562);
  }
  
  textSize(50);
  text(bateria, 790, 680);
  
  // Botões de Alerta/Box
  if (botao_piloto1 == 1) image(aleon, 20, 200);
  else image(aleoff, 20, 200);
  
  if (alerta_telemetria == 1) image(boxon, 20, 350);
  else image(boxoff, 20, 350);
  
  // Temperatura CVT
  if (temperatura < 43) {
    tp0.resize(0, 160);
    image(tp0, 740, 720);
  }
  
  if (temperatura >= 44 & temperatura < 51) {
    tp1.resize(0, 160);
    image(tp1, 740, 720);
  }
  
  if (temperatura >= 52 & temperatura < 59) {
    tp2.resize(0, 160);
    image(tp2, 740, 720);
  }
  
  if (temperatura >= 60 & temperatura < 67) {
    tp3.resize(0, 160);
    image(tp3, 740, 720);
  }
  
  if (temperatura >= 68 & temperatura < 75) {
    tp4.resize(0, 160);
    image(tp4, 740, 720);
  }
  
  if (temperatura >= 76 & temperatura < 83) {
    tp5.resize(0, 160);
    image(tp5, 740, 720);
  }
  
  if (temperatura >= 84 & temperatura < 91) {
    tp6.resize(0, 160);
    image(tp6, 740, 720);
  }
  
  if (temperatura >= 92 & temperatura < 99) {
    tp7.resize(0, 160);
    image(tp7, 740, 720);
  }
  
  if (temperatura > 100) {
    tp8.resize(0, 160);
    image(tp8, 740, 720);
  }
  textSize(50);
  text(temperatura, 850, 810);
  
  // Combustível
  if(combustivel < 25) image(comb1, 326, 767);
  
  if(combustivel > 26 & combustivel <= 50) image(comb2, 326, 767);
  
  if(combustivel > 51 & combustivel <= 75) image(comb3, 326, 767);
  
  if(combustivel > 75) image(comb4, 326, 767);
  
  // TPMS
  fill(255);
  
  // 1
  textSize(40);
  text(tep1, 1070, 220);
  textSize(60);
  text(pres1, 1090, 280);
  
  // 2
  textSize(40);
  text(tep2, 1320, 220);
  textSize(60);
  text(pres2, 1340, 280);
  
  // 3
  textSize(40);
  text(tep3, 1070, 790);
  textSize(60);
  text(pres3, 1090, 850);
  
  // 4
  textSize(40);
  text(tep4, 1320, 790);
  textSize(60);
  text(pres4, 1340, 850);
  
  
  // Pressão Transdutor
  fill(0);
  textSize(30);
  text("bar", 190, 840);
  textSize(70);
  text(pressao_linha_dianteira, 70, 850);
  
  // Posição dos pedais
  fill(#F01C0A);
  rect(14, 608, 331 * (posicao_freio/100), 20);
  
  rect(374, 608, 331 * (posicao_acelerador/100), 20);
}
