#include "dht.h" //INCLUSÃO DE BIBLIOTECA
#include <Wire.h>                // Biblioteca para comunicação I2C
#include <LiquidCrystal_I2C.h>   // Biblioteca para controle do display I2C

#define col 16    // Número de colunas do display
#define lin  2    // Número de linhas do display
#define ende  0x27 // Endereço do display I2C

LiquidCrystal_I2C lcd(ende, col, lin); // Inicializa o display I2C com o endereço e dimensões

const int pinoDHT11 = A2; //PINO ANALÓGICO UTILIZADO PELO DHT11
 
dht DHT; //VARIÁVEL DO TIPO DHT
 
void setup(){
  lcd.init();        // Inicia o display
  lcd.backlight();   // Liga a luz de fundo do display
  lcd.clear();       // Limpa o display
  Serial.begin(9600); //INICIALIZA A SERIAL
}
 
void loop(){
  DHT.read11(pinoDHT11); //LÊ AS INFORMAÇÕES DO SENSOR
  Serial.print("Umidade: "); //IMPRIME O TEXTO NA SERIAL
  Serial.print(DHT.humidity); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO
  Serial.print("%"); //ESCREVE O TEXTO EM SEGUIDA
  Serial.print(" / Temperatura: "); //IMPRIME O TEXTO NA SERIAL
  Serial.print(DHT.temperature, 0); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO E REMOVE A PARTE DECIMAL
  Serial.println("*C"); //IMPRIME O TEXTO NA SERIAL

  delay(2000); //INTERVALO DE 2 SEGUNDOS * NÃO DIMINUIR ESSE VALOR
  lcd.setCursor(0, 0);         // Define o cursor na primeira coluna e primeira linha
  lcd.print(DHT.temperature);        // Imprime a mensagem na primeira linha

  // Linha 2
  lcd.setCursor(0, 1);         // Define o cursor na primeira coluna e segunda linha
  lcd.print("Graus Celcius");      // Imprime a mensagem na segunda linha
  delay(2000);                 // Aguarda 2 segundos
  
  lcd.clear();                 // Limpa o display para novas mensagens
  
  // Alternando mensagens
  lcd.setCursor(0, 0);
  lcd.print(DHT.humidity);
  lcd.setCursor(0, 1);
  lcd.print("Umidade no ar");
  delay(2000);

  lcd.clear(); // Limpa o display
}