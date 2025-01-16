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
  if(valor > 0 ){
    //acende o led com intensiaded proporcional ao valor obtido
    analogWrite(LED, (valor/4));
    Serial.println(valor);
  }
}
