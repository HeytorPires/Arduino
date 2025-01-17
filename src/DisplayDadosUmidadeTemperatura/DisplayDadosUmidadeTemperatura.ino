#include <Servo.h> // Inclusão da biblioteca Servo para controle do motor servo

const int pinoServo = 6; // Pino digital conectado ao servo motor

Servo s; // Criação do objeto Servo

void setup() {
  s.attach(pinoServo); // Associa o pino digital ao objeto Servo
  s.write(0);          // Define a posição inicial do servo em 0º
}

void loop() {
  s.write(180); // Move o servo para 180º
  delay(2000);  // Aguarda 2 segundos

  s.write(0);   // Move o servo de volta para 0º
  delay(2000);  // Aguarda 2 segundos
}
