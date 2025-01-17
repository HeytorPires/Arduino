#include <Wire.h>                // Biblioteca para comunicação I2C
#include <LiquidCrystal_I2C.h>   // Biblioteca para controle do display I2C

#define col 16    // Número de colunas do display
#define lin  2    // Número de linhas do display
#define ende  0x27 // Endereço do display I2C

LiquidCrystal_I2C lcd(ende, col, lin); // Inicializa o display I2C com o endereço e dimensões

const int pinoDHT11 = A3; //PINO ANALÓGICO UTILIZADO PELO DHT11
int eixo_X = A0; //PINO REFERENTE A LIGAÇÃO DO EIXO X
int eixo_Y = A1; //PINO REFERENTE A LIGAÇÃO DO EIXO Y
int botao = 2;   //PINO REFERENTE AO BOTÃO (EIXO Z)

void setup() {
  lcd.init();          // Inicia o display
  lcd.backlight();     // Liga a luz de fundo do display
  lcd.clear();         // Limpa o display
  pinMode(botao, INPUT_PULLUP); // Configura o botão como entrada com resistor pull-up
  Serial.begin(9600);  // Inicializa o monitor serial
}

void loop() {
  int valorX = analogRead(eixo_X); // Lê o valor do eixo X
  int valorY = analogRead(eixo_Y); // Lê o valor do eixo Y
  int botaoEstado = digitalRead(botao); // Lê o estado do botão
  
   lcd.setCursor(0, 1); // Define o cursor na primeira linha
  lcd.print("ULTIMA ACAO"); // Limpa a linha escrevendo espaços


  if (valorX == 0) { // Para cima
    Serial.println("PARA CIMA");
    lcd.setCursor(0, 0); // Define o cursor na primeira linha
  lcd.print("                "); // Limpa a linha escrevendo espaços
    lcd.setCursor(0, 0);
    lcd.print("PARA CIMA");
  } 
  else if (valorX == 1023) { // Para baixo
  lcd.setCursor(0, 0); // Define o cursor na primeira linha
  lcd.print("                "); // Limpa a linha escrevendo espaços
    Serial.println("PARA BAIXO");
    lcd.setCursor(0, 0);
    lcd.print("PARA BAIXO");
  } 
  else if (valorY == 0) { // Direita
  lcd.setCursor(0, 0); // Define o cursor na primeira linha
  lcd.print("                "); // Limpa a linha escrevendo espaços
    Serial.println("DIREITA");
    lcd.setCursor(0, 0);
    lcd.print("DIREITA");
  } 
  else if (valorY == 1023) { // Esquerda
  lcd.setCursor(0, 0); // Define o cursor na primeira linha
  lcd.print("                "); // Limpa a linha escrevendo espaços
    Serial.println("ESQUERDA");
    lcd.setCursor(0, 0);
    lcd.print("PETISTA");
  } 
  else if (botaoEstado == LOW) { // Botão pressionado
  lcd.setCursor(0, 0); // Define o cursor na primeira linha
  lcd.print("                "); // Limpa a linha escrevendo espaços
    Serial.println("BOTAO PRESSIONADO");
    lcd.setCursor(0, 0);
    lcd.print("BOTAO PRESSIONADO");
  }
  
  delay(500); // Aguarda 500ms
}
