#include <Wire.h>

#define DS1307_ADDRESS_1 0x68  // Endereço I2C padrão para o RTC DS1307
#define DS1307_ADDRESS_2 0x57  // Outro endereço possível

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Serial.println("Testando comunicação com o RTC...");

  // Tenta comunicar com o primeiro endereço
  Wire.beginTransmission(DS1307_ADDRESS_1);
  byte error = Wire.endTransmission();
  if (error == 0) {
    Serial.println("Comunicação com o RTC no endereço 0x68 bem-sucedida!");
  } else {
    Serial.println("Falha na comunicação com o RTC no endereço 0x68.");
  }

  // Tenta comunicar com o segundo endereço
  Wire.beginTransmission(DS1307_ADDRESS_2);
  error = Wire.endTransmission();
  if (error == 0) {
    Serial.println("Comunicação com o RTC no endereço 0x57 bem-sucedida!");
  } else {
    Serial.println("Falha na comunicação com o RTC no endereço 0x57.");
  }
}

void loop() {
  // Nada a fazer no loop
}
