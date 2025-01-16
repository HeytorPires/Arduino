#include <Wire.h>                // Biblioteca para comunicação I2C
#include <LiquidCrystal_I2C.h>   // Biblioteca para controle do display I2C

#define col 16    // Número de colunas do display
#define lin  2    // Número de linhas do display
#define ende  0x27 // Endereço do display I2C

LiquidCrystal_I2C lcd(ende, col, lin); // Inicializa o display I2C com o endereço e dimensões

void setup() {  
  lcd.init();        // Inicia o display
  lcd.backlight();   // Liga a luz de fundo do display
  lcd.clear();       // Limpa o display
}

void loop() {
  // Linha 1
  lcd.setCursor(0, 0);         // Define o cursor na primeira coluna e primeira linha
  lcd.print("MILENA ");        // Imprime a mensagem na primeira linha
  delay(2000);                 // Aguarda 2 segundos

  // Linha 2
  lcd.setCursor(0, 1);         // Define o cursor na primeira coluna e segunda linha
  lcd.print("EU TE AMO");      // Imprime a mensagem na segunda linha
  delay(2000);                 // Aguarda 2 segundos
  
  lcd.clear();                 // Limpa o display para novas mensagens
  
  // Alternando mensagens
  lcd.setCursor(0, 0);
  lcd.print("TOTOI TE AMA");
  lcd.setCursor(0, 1);
  lcd.print("MILENINHA!");
  delay(2000);

  lcd.clear(); // Limpa o display
}
