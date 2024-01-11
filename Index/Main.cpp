#include <Servo.h>
//-----------------------------------------
//              Iluminação Geral
//-----------------------------------------

//1ºandar
#define sala 52
#define area 50
#define cozinha 48
#define garagem 46
#define banheiro 44

//2ºandar
#define suite 42
#define quarto1 40
#define quarto2 38
#define quarto3 36

// LDR
#define ledLDR 8
const int LDR = A0;
int valorsensor;

//Servo Motores - Garagem e Acesso
Servo portaoexterno;
Servo portaogaragem;

char command;

void setup() {
  pinMode(sala, OUTPUT);
  pinMode(area, OUTPUT);
  pinMode(cozinha, OUTPUT);
  pinMode(garagem, OUTPUT);
  pinMode(banheiro, OUTPUT);
  pinMode(suite, OUTPUT);
  pinMode(quarto1, OUTPUT);
  pinMode(quarto2, OUTPUT);
  pinMode(quarto3, OUTPUT);
  pinMode(externo, OUTPUT);
  Serial.begin(9600);
  pinMode(ledLDR, OUTPUT);
  pinMode(LDR, INPUT);
  portaogaragem.attach(7);
  portaoexterno.attach(6);

}

void loop() {

//Comunicação entre Aplicativo e Arduino

  if (Serial.available()) {
    command = Serial.read();
    switch (command) {
      case 'A':
        OnSala();
        break;
      case 'a':
        OffSala();
        break;
      case 'B':
        OnArea();
        break;
      case 'b':
        OffArea();
        break;
      case 'C':
        OnCozinha();
        break;
      case 'c':
        OffCozinha();
        break;
      case 'D':
        OnGaragem();
        break;
      case 'd':
        OffGaragem();
        break;
      case 'E':
        OnBanheiro();
        break;
      case 'e':
        OffBanheiro();
        break;
      case 'F':
        OnSuite();
        break;
      case 'f':
        OffSuite();
        break;
      case 'G':
        OnQuarto1();
        break;
      case 'g':
        OffQuarto1();
        break;
      case 'H':
        OnQuarto2();
        break;
      case 'h':
        OffQuarto2();
        break;
      case 'I':
        OnQuarto3();
        break;
      case 'i':
        OffQuarto3();
        break;
      case 'J':
        OnAll();
        break;
      case 'j':
        OffAll();
        break;
      case 'K':
        AbrirPortaoGaragem();
        break;
      case 'k':
        FecharPortaoGaragem();
        break;
      case 'L':
        AbrirPortaoExterno();
        break;
      case 'l':
        FecharPortaoExterno();
        break;
    }
  }

// Funcionamento LDR
  valorsensor = analogRead(LDR);
  Serial.print("LDR : ");
  Serial.println(valorsensor);

  if (valorsensor < 520) {
    digitalWrite(ledLDR, HIGH);
  } else {
    digitalWrite(ledLDR, LOW);
  }
  delay(100);
}

// Controle por Aplicativo da Iluminação e Motores (Funções)

void OnSala() {
  digitalWrite(sala, HIGH);
}

void OffSala() {
  digitalWrite(sala, LOW);
}

void OnArea() {
  digitalWrite(area, HIGH);
}

void OffArea() {
  digitalWrite(area, LOW);
}

void OnCozinha() {
  digitalWrite(cozinha, HIGH);
}

void OffCozinha() {
  digitalWrite(cozinha, LOW);
}

void OnGaragem() {
  digitalWrite(garagem, HIGH);
}

void OffGaragem() {
  digitalWrite(garagem, LOW);
}

void OnBanheiro() {
  digitalWrite(banheiro, HIGH);
}

void OffBanheiro() {
  digitalWrite(banheiro, LOW);
}

void OnSuite() {
  digitalWrite(suite, HIGH);
}

void OffSuite() {
  digitalWrite(suite, LOW);
}

void OnQuarto1() {
  digitalWrite(quarto1, HIGH);
}

void OffQuarto1() {
  digitalWrite(quarto1, LOW);
}

void OnQuarto2() {
  digitalWrite(quarto2, HIGH);
}

void OffQuarto2() {
  digitalWrite(quarto2, LOW);
}

void OnQuarto3() {
  digitalWrite(quarto3, HIGH);
}

void OffQuarto3() {
  digitalWrite(quarto3, LOW);
}

void OnAll() {
  digitalWrite(sala, HIGH);
  digitalWrite(area, HIGH);
  digitalWrite(cozinha, HIGH);
  digitalWrite(garagem, HIGH);
  digitalWrite(banheiro, HIGH);
  digitalWrite(suite, HIGH);
  digitalWrite(quarto1, HIGH);
  digitalWrite(quarto2, HIGH);
  digitalWrite(quarto3, HIGH);
}

void OffAll() {
  digitalWrite(sala, LOW);
  digitalWrite(area, LOW);
  digitalWrite(cozinha, LOW);
  digitalWrite(garagem, LOW);
  digitalWrite(banheiro, LOW);
  digitalWrite(suite, LOW);
  digitalWrite(quarto1, LOW);
  digitalWrite(quarto2, LOW);
  digitalWrite(quarto3, LOW);        
}

void AbrirPortaoGaragem(){
  portaogaragem.write(180);
  delay(500);
}

void FecharPortaoGaragem(){
  portaogaragem.write(0);
  delay(500);
}

void AbrirPortaoExterno(){
  portaoexterno.write(180);
  delay(500);
}

void FecharPortaoExterno(){
  portaoexterno.write(0);
  delay(500);
}
