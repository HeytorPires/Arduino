// C++ code
// potenciometro
int pot = A1;

// pino LED
int LED = 13;

// variável para armazenar o valor lido
int valor = 0;

void setup()
{
  // Inicializa o pino do LED como saída
  pinMode(LED, OUTPUT);

  // Inicializa a comunicação serial a 9600 bps
  Serial.begin(9600);
}

void loop()
{
  // Lê o valor do potenciômetro
  valor = analogRead(pot);

  // Imprime o valor lido no monitor serial
  Serial.println(valor);

  // Controla o LED com atraso baseado no valor do potenciômetro
  digitalWrite(LED, HIGH);
  //a Velocidade entre um pisque e outro
  delay(valor); 
  digitalWrite(LED, LOW);
  delay(valor); 
}
