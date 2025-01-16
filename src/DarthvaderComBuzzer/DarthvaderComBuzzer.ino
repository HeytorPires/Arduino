// C++ code
//
int led = 9;
int botao = 7;
int valor;
int buzz = 13;
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // obtém LOW ( botão não selecionado) ou
  // HIGH(botão selecionado)
  valor = digitalRead(botao);

  if(valor == HIGH){
  digitalWrite(led, valor);
  tone(buzz, 400);
  } else{
    digitalWrite(led, valor);
   noTone(buzz) 
  ;}

  Serial.println(valor);
  // delay(500);
}