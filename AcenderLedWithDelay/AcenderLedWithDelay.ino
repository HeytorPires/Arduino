// Preparação do Arduino, este código irá rodar uma única vez
int led_vermelho = 2;
int led_Amarelo= 4;
int led_Verde = 6;

int led_pedestre_pode = 9;
int led_pedestre_nao = 11;

void setup() 
{
  // Colocamos o pino 12 do Arduino como OUTPUT (saída)
  pinMode(led_Verde, OUTPUT);
  pinMode(led_Amarelo, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_pedestre_pode, OUTPUT);
  pinMode(led_pedestre_nao, OUTPUT);

}

// Este código é chamado automáticamente pelo Arduino, ficará em
// loop até que seu Arduino seja desligado
void loop() 
{
  // Ativamos o pino 12 (colocando 5v nele)  
  digitalWrite(led_Verde, HIGH);
  digitalWrite(led_pedestre_nao, HIGH);
  delay(10000);
  digitalWrite(led_Amarelo, HIGH);
  digitalWrite(led_Verde, LOW);

  delay(2000);
  digitalWrite(led_pedestre_nao, LOW);
  digitalWrite(led_pedestre_pode, HIGH);
  digitalWrite(led_vermelho, HIGH);
  digitalWrite(led_Amarelo, LOW);
  // Aguardamos 1 segundo
  delay(10000);
  digitalWrite(led_vermelho, LOW);
  digitalWrite(led_pedestre_pode, LOW);
  

  // // Desligamos o pino 12
  // digitalWrite(led_Verde, LOW);
  // digitalWrite(led_Amarelho, LOW);
  // digitalWrite(led_vermelho, LOW);



  // Aguardamos mais um segundo
  // delay(100);

  // Este código irá se repetir eternamente
}