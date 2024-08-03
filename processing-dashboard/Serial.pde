// Programação da comunicação serial com referência na programação do Iotti - by Enzimas

//------ Variáveis da telemetria ----------------------------------------
//-----------------------------------------------------------------------
int pressao_linha_dianteira = 0;
int pressao_linha_traseira = 0;

int velocidade_dianteira = 0;
int bateria = 10;
int temperatura = 28; 
int rpm_dezena = 0;
int rpm_unidade = 0;
int combustivel = 90;
int velocidade_traseira = 0;

int aceleracao_em_x = 0;
int aceleracao_em_y = 0;
int aceleracao_em_z = 0;

int giro_em_x = 0;
int giro_em_y = 0;
int giro_em_z = 0;

int tep1 = 23;
int pres1 = 5;

int tep2 = 23;
int pres2 = 5;

int tep3 = 23;
int pres3 = 7;

int tep4 = 23;
int pres4 = 7;

float posicao_acelerador = 0;
float posicao_freio = 0;
int posicao_volante = 0;

int botao_piloto1 = 0;
int botao_piloto2 = 0;
int botao_piloto3 = 0;

int x = 0;
int y = 0;

int alerta_telemetria = 0;

//---- Variáveis processadas -------------------------------------------- 
int velocidade = 0;
int rpm = 0;

float forca_g_x = 0;
float forca_g_y = 0;
float forca_g_z = 0;

int raster_dianteira = 1;
int raster_traseira = 1;
int raster_telemetria = 1;
int raster_display = 1;
int raster_tpms1 = 1;
int raster_tpms2 = 1;
int raster_tpms3 = 1;
int raster_tpms4 = 1;
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------  
//-----------------------------------------------------------------------

/* Função que recebe a entrada da serial do LoRa */
void serialEvent (Serial myPort) {
    
  String input = myPort.readStringUntil('\n');                                     // recebe a nova entrada da porta serial
  
  if (input != null) {                                                             // se entrada for diferente de zero
    input = trim(input);                                                           // recorta nova entrada no tamanho mínimo dela
    String[] valores = split(input, " ");                                          // separa cada informação a partir de espaços e armazena eles no vetor de string
    
    if (valores.length != 32) return;                                              // se o vetor não possuir 32 informações, ocorreu erro na transmissão
    
      /* Valores de pressão das linhas de freio */                                 // aqui começa o vetor recebido na telemetria
      pressao_linha_dianteira  =  int(valores[0]);                                 //
      pressao_linha_traseira   =  int(valores[1]);                                 //
      
      /* Dados gerais */
      velocidade_dianteira     =  int(valores[2]);                                 
      bateria                  =  int(valores[3]);                                 
      temperatura              =  int(valores[4]);
      rpm_dezena               =  int(valores[5]);
      rpm_unidade              =  int(valores[6]);
      combustivel              =  int(valores[7]);
      velocidade_traseira      =  int(valores[8]);                                  
      
      /* Acelerometria */
      aceleracao_em_x          =  int(valores[9]);
      aceleracao_em_y          =  int(valores[10]);
      aceleracao_em_z          =  int(valores[11]);
      
      /* Giro */
      giro_em_x                =  int(valores[12]);
      giro_em_y                =  int(valores[13]);
      giro_em_z                =  int(valores[14]);
      
      /* Espaço livre na 16ª posição do vetor (valores[15]) */
      
      /* Temperatura e pressão TPMS */
      tep1                     =  int(valores[16]);
      pres1                    =  int(valores[17]);
      tep2                     =  int(valores[18]);
      pres2                    =  int(valores[19]);
      tep3                     =  int(valores[20]);
      pres3                    =  int(valores[21]);
      tep4                     =  int(valores[22]);
      pres4                    =  int(valores[23]);
      
      /* Posicionamentos */
      posicao_acelerador       =  int(valores[24]);
      posicao_freio            =  int(valores[25]);
      posicao_volante          =  int(valores[26]);
      
      /* Botões do Piloto */
      botao_piloto1            =  int(valores[27]);
      botao_piloto2            =  int(valores[28]);
      botao_piloto3            =  int(valores[29]);
      
      /* Coordenadas GPS*/
      x                        =  int(valores[30]);
      y                        =  int(valores[31]);
      
      /* Calculo da Velocidade */                                                  // aqui começa o processamento e formatação dos dados recebidos                    
      velocidade = ((velocidade_dianteira + velocidade_traseira)/2);
      
      /* Função que junta as partes do RPM */
      rpm = (rpm * 100) + rpm_unidade;  
    
      /* Cálculo da força G */
      forca_g_x = (aceleracao_em_x/10);
      forca_g_y = (aceleracao_em_y/10);
      forca_g_z = (aceleracao_em_z/10);
  }    
}
