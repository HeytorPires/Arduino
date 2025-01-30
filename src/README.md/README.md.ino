mo#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

// Definição dos pinos do display
#define TFT_CS 10
#define TFT_RST 9
#define TFT_DC 8

// Inicializa o display
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  // Inicializa o display
  tft.initR(INITR_BLACKTAB);  // Modelo com fundo preto
  tft.setRotation(1);         // Rotação da tela (0-3)

  // Preenche a tela com preto
  tft.fillScreen(ST77XX_BLACK);

  // Exemplo: Exibe texto
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("Te amo, Milena!");
}

void loop() {
  // Nada no loop por enquanto
}
