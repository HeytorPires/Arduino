int led = 9;
int botao = 7;
int valor;
int valorAnterior = 0;
int estado = LOW;
int buzz = 13;
int brilho = 128;        // Brilho inicial
unsigned long inicio;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(buzz, OUTPUT);
  
  analogWrite(led, 255); // LED ligado continuamente no brilho máximo
}

void loop() {
  // Lê o estado do botão (LOW ou HIGH)
  valor = digitalRead(botao);

  // Verifica se o botão foi pressionado e muda o estado do buzzer
  if (valor == HIGH && valorAnterior == LOW) {
    estado = !estado;    // Alterna o estado entre HIGH e LOW para o buzzer
    inicio = millis();   // Marca o tempo de início da pressão
    delay(50);           // Anti-rebote
  }

  // Verifica se o botão está pressionado continuamente
  if (valor == HIGH && valorAnterior == HIGH) {
    // Se o botão está pressionado por mais de 0,5 segundos, ajusta o brilho
    if ((millis() - inicio) > 500) {
      brilho++;          // Aumenta o brilho
      delay(10);         // Pequeno atraso para suavizar o ajuste de brilho
      if (brilho > 255)  // Reseta o brilho se exceder o máximo
        brilho = 0;

      analogWrite(led, brilho);  // Ajusta o brilho do LED
    }
  }

  // Controla o buzzer com base no estado
  if (estado == HIGH) {
    tone(buzz, 400);    // Ativa o buzzer com frequência de 400 Hz
  } else {
    noTone(buzz);       // Desativa o buzzer
  }

  valorAnterior = valor; // Atualiza o valor anterior do botão
}
