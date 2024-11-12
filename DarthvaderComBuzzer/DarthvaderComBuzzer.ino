// Pino do buzzer
int buzzer = 8;

// Notas de "Blue Bird" em frequências (Hz)
int notes[] = {
  523, 587, 659, 523, 523, 587, 659, 523,   // "Habataitara modoranai to itte"
  659, 698, 784, 659, 587, 523, 523, 587,   // "mezashita no wa aoi aoi ano sora"
  523, 587, 659, 523, 523, 587, 659, 523,   // "kanashimi wa mada oboerarezu"
  659, 698, 784, 659, 587, 523              // "setsunasa wa ima tsukami hajimeta"
};

// Duração das notas em milissegundos (aproximada)
int durations[] = {
  300, 300, 600, 300, 300, 300, 600, 300, 
  300, 300, 600, 300, 300, 300, 300, 600,
  300, 300, 600, 300, 300, 300, 600, 300,
  300, 300, 600, 300, 300, 800
};

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  for (int i = 0; i < sizeof(notes) / sizeof(notes[0]); i++) {
    tone(buzzer, notes[i]);         // Toca a nota
    delay(durations[i]);            // Duração da nota
    noTone(buzzer);                 // Silencia o buzzer entre as notas
    delay(50);                      // Pequena pausa entre as notas
  }
  delay(3000);                      // Pausa entre as repetições da melodia
}
