// Pino do buzzer
int buzzer = 8;

// Frequências das notas da Marcha Imperial (tema de Darth Vader)
int notes[] = {
  440, 440, 440, 349, 523, 440, 349, 523, 440,   // "Darth Vader theme"
  659, 659, 659, 698, 523, 415, 349, 523, 440
};

// Duração das notas (em ms)
int durations[] = {
  500, 500, 500, 350, 150, 500, 350, 150, 1000,  // Duração das notas
  500, 500, 500, 350, 150, 500, 350, 150, 1000
};

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  for (int i = 0; i < sizeof(notes) / sizeof(notes[0]); i++) {
    tone(buzzer, notes[i]);         // Toca a nota
    delay(durations[i]);            // Duração da nota
    noTone(buzzer);                 // Pausa entre as notas
    delay(50);                      // Pequena pausa entre as notas
  }
  delay(2000);                      // Pausa entre as repetições da melodia
}
