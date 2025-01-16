int led = 9;
int botao = 7;
int valor;
int anterior = 0;
int estado = LOW;
int buzz = 13;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(buzz, OUTPUT);
}

void loop() {
  // Lê o estado do botão (LOW ou HIGH)
  valor = digitalRead(botao);

  // Verifica se o botão foi pressionado e muda o estado
  if (valor == HIGH && anterior == LOW) {
    estado = !estado;  // Alterna o estado entre HIGH e LOW
    delay(50);         // Anti-rebote
  }

  // Atualiza o estado do LED e do buzzer
  digitalWrite(led, estado);     // Liga/desliga o LED conforme o estado
  if (estado == HIGH) {
    tone(buzz, 400);             // Ativa o buzzer com frequência de 400 Hz
  } else {
    noTone(buzz);                // Desativa o buzzer
  }

  anterior = valor; // Atualiza o valor anterior do botão
}
