// pino do led 
int led = 13;

// pino ldr 
int ldr = A0;

//variavel que recebe o valor do ldr
int entrada = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  entrada = analogRead(ldr);
  Serial.println(entrada);
  if( entrada < 500) {
	digitalWrite(led, HIGH);
  } else {
	digitalWrite(led, LOW);
  }
  delay(1000);
    
}