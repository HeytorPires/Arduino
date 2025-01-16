// C++ code
//
int buzzer = 8;
void setup()
{
  pinMode(buzzer, OUTPUT);
}

void loop()
{
	tone(buzzer, 440); //liga passando a frequencia
	delay(500);	
	noTone(buzzer); //desliga
	delay(500);
  
}