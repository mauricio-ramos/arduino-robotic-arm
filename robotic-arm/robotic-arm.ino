#include <Servo.h> //BIBLIOTECA DE FUNÇÕES COM MOTORES SERVOS

// DECLARAÇÃO DOS MOTORES UZADOS NO PROJETO...
Servo servoBase; //RODA ESQUERDA DA BASE DO BRAÇO....
Servo servoGarra; //GARRA DO B RAÇO MECÂNICO...
Servo servoBraco; //MOTOR RESPONSÁVEL PELA MOVIMENTAÇÃO VERTICL DO BRAÇO...
Servo servoBraco2;

int posicaoBraco = 0;
int posicaoGarra = 160;
int posicaoBase = 90;

//FUNÇÃO ONDE SÃO ESPECIFICADAS AS CONFIGURAÇÕES DO PROJETO...
void setup() {

  //ATRIBUIÇÃO DE PINOS PARA OS MOTORES
  servoGarra.attach(10);
  servoBraco.attach(5);
  servoBraco2.attach(6);
  servoBase.attach(9);
  Serial.begin(9600);
}

//FUNÇÃO QUE MANTÉN OS DOIS SERVOS DE ROTAÇÃO CONTÍNUA USADOS NAS RODAS PARADOS (ROBÔ PARADO)...
void parado() {
  //servoDir.write(87);
  //servoEsq.write(90);
}
//FUNÇÃO RESPONSÁVEL POR GIRAR A BASE PARA A DIREITA...
void direita() {
  //servoEsq.write(0);
  int i;
  for (i = posicaoBase; i >= 20; i--) {
    servoBase.write(i);
    delay(20); //GIRA POR ATÉ ATINGIR UM ÂNGULO DE APROX.90 GRAUS E PARA...
    //parado();
  }

  posicaoBase = i;
}

//FUNÇÃO RESPONSÁVEL POR GIRAR A BASE PARA A ESQUERDA...
void esquerda() {
  //servoEsq.write(180);

  int i;
  for (i = posicaoBase; i <= 160; i++) {
    servoBase.write(i);
    delay(20);     //GIRA POR ATÉ ATINGIR UM ÂNGULO DE APROX. 90 GRAUS E PARA...
    //parado();
  }

  posicaoBase = i;

}

void centro() {
  //servoEsq.write(180);
  int i;

  if (posicaoBase < 90) {
    for (i = posicaoBase; i <= 90; i++) {
      servoBase.write(i);
      delay(20);     //GIRA POR ATÉ ATINGIR UM ÂNGULO DE APROX. 90 GRAUS E PARA...
      //parado();
    }

  } else if (posicaoBase > 90) {
    for (i = posicaoBase; i >= 90; i--) {
      servoBase.write(i);
      delay(20); //GIRA POR ATÉ ATINGIR UM ÂNGULO DE APROX.90 GRAUS E PARA...
      //parado();
    }

  }
  //servoBase.write(90);
  //delay(60);     //GIRA POR ATÉ ATINGIR UM ÂNGULO DE APROX. 90 GRAUS E PARA...
  //parado();
  posicaoBase = i;
}

// FUNÇÃO RESPONSÁVELPORLEVANTAR O BRAÇO MECÂNICO...
void sobeBraco() {
  //         servoBraco.write(180);
  //         servoBraco2.write(0);
  //servoBraco2.write(110);
  int i;
  for ( i = 100; i < 180; i++) {
    //Serial.print(180-i);
    //Serial.print(" ");
    servoBraco.write(i);
    //servoBraco2.write(i);
    delay(45);
  }
  posicaoBraco = i;
}

//FUNÇÃO RESPONSÁVEL POR BAIXAR O BRAÇO MECÂNICO...
void baixaBraco() {
  int i;
  for (i = 180; i > 100; i--) {
    //Serial.print(180-i);
    //Serial.print(" ");
    servoBraco.write(i);
    //servoBraco2.write(i);
    delay(45);
  }
  posicaoBraco = i;
}

// FUNÇÃO RESPONSÁVEL POR MOVIMENTAR PARA A FRENTE O BRAÇO MECÂNICO...
void bracoFrente() {
  int i;
  for ( i = 90; i < 180; i++) {
    servoBraco2.write(i);
    Serial.print("");
    //servoBraco2.write(i);
    delay(45);
  }
  //posicaoBraco = i;
}

//FUNÇÃO RESPONSÁVEL POR MOVIMENTAR PARA TRAS O BRAÇO MECÂNICO...
void bracoTras() {
  int i;
  for ( i = 180; i > 90; i--) {
    servoBraco2.write(i);
    Serial.print("");
    //servoBraco2.write(i);
    delay(45);
  }
  //posicaoBraco = i;
}

// FUNÇÃO QU ABRE A GARRA...
void abre() {
  int i;
  for (i = posicaoGarra; i > 80; i--) {
    servoGarra.write(i);
    delay(40);
    Serial.print(servoGarra.read());
    Serial.print(" - ");
  }
  posicaoGarra = i;
}

// FUNÇÃO QU FECHA A GARRA...
void fecha() {
  int i;
  for (i = posicaoGarra; i < 160; i++) {
    servoGarra.write(i);
    delay(40);
    Serial.print(servoGarra.read());
    Serial.print(" - ");
  }
  posicaoGarra = i;
}

// FUNÇÃO QU ABRE A GARRA...
void zera() {
  Serial.print(servoBraco.read());
  Serial.print(" - ");
  //Serial.print(servoBraco2.read());

  //servoBraco.write(100);
  delay(40);
  servoBraco.write(0);
  delay(40);

  //servoBraco2.write(90);

  Serial.print(servoBraco.read());
  Serial.print(" - ");
  //Serial.print(servoBraco2.read());


  /*int a = 0;

    for (a = 180; a > 0; a--) {
    servoBraco.write(a);
    //servoBraco2.write(a);
    delay(5);
    }

    int b = 0;
    for (b = 0; b < 120; b++) {
    //servoBraco.write(a);
    servoBraco2.write(b);
    delay(5);
    }*/
}

void posicaoInicial() {
  servoGarra.write(160);
  servoBase.write(90);

}

void loop() {
  char tecla = Serial.read();
  // A PORTA SERIAL LÊ UMA TECLA DIGITADA NO TECLADO DO COMPUTADOR...
  //E DE ACORDO COM O CARACTER LIDO CHAMA UMA DAS FUNÇÕES ACIMA...
  //zera(tecla);



  //CASO PRESSIONE A TECLA 'D', O ROBO GIRA PARA A DIREITA...
  if (tecla == 'z' || tecla == 'Z') {
    zera();
  }

  //CASO PRESSIONE A TECLA 'D', O ROBO GIRA PARA A DIREITA...
  if (tecla == 'd' || tecla == 'D') {
    direita();
  }

  //CASO PRESSIONE A TECLA 'D', O ROBO GIRA PARA A ESQUERDA...
  else if (tecla == 'e' || tecla == 'E') {
    esquerda();
  }

  //CASO PRESSIONE A TECLA 'C', O ROBO GIRA PARA o centro...
  else if (tecla == 'c' || tecla == 'C') {
    centro();
  }

  //CASO PRESSIONE A TECLA 'A', O ROBO ABRE A GARRA...
  else if (tecla == 'a' || tecla == 'A') {
    abre();
  }

  //CASO PRESSIONE A TECLA 'F', O ROBO FECHA A GARRA...
  else if (tecla == 'f' || tecla == 'F') {
    fecha();
  }

  //CASO PRESSIONE A TECLA 'S', O ROBO SOBE O BRAÇO...
  else if (tecla == 's' || tecla == 'S') {
    sobeBraco();
  }

  //CASO PRESSIONE A TECLA 'B', O ROBO BAIXA O BRAÇO..
  else if (tecla == 'b' || tecla == 'B') {
    baixaBraco();
  }

  //CASO PRESSIONE A TECLA 'S', O ROBO SOBE O BRAÇO...
  else if (tecla == 'r' || tecla == 'R') {
    bracoFrente();
  }

  //CASO PRESSIONE A TECLA 'B', O ROBO BAIXA O BRAÇO...
  else if (tecla == 't' || tecla == 'T') {
    bracoTras();
  }

  // CASO NÃO PRESSIONE NENHUMA TECLA O ROBÔ PERMANECE PARADO...
  else {
    parado();
  }
}
