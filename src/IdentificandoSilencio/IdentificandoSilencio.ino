const int pinoRele = 2; //PINO DIGITAL UTILIZADO PELO MÓDULO RELÉ
const int pinoBotao = 8; //PINO DIGITAL UTILIZADO PELO BOTÃO
int statusLamp = 0; //VARIÁVEL QUE CONTROLA O ESTADO DO MÓDULO RELÉ (LIGADO / DESLIGADO)

void setup(){
  pinMode(pinoRele, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pinoBotao, INPUT_PULLUP); //DEFINE O PINO COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
  //DO ARDUINO PARA GARANTIR QUE NÃO EXISTA FLUTUAÇÃO ENTRE 0 (LOW) E 1 (HIGH)
  digitalWrite(pinoRele, HIGH); //MÓDULO RELÉ INICIA DESLIGADO
}    
void loop(){
 if((digitalRead(pinoBotao) == LOW) && (statusLamp == 0)){ //SE A LEITURA DO PINO FOR IGUAL A LOW E
    //VARIÁVEL statusLamp FOR IGUAL A 0, FAZ
        digitalWrite(pinoRele, LOW); //LIGA O MÓDULO RELÉ (LÂMPADA ACENDE)
        statusLamp = 1; //VARIÁVEL RECEBE O VALOR 1
        delay(200); //INTERVALO DE 200 MILISSEGUNDOS
 }else{//SENÃO, FAZ
      if((digitalRead(pinoBotao) == LOW) && (statusLamp == 1)){ //SE A LEITURA DO PINO FOR IGUAL A LOW E
       //VARIÁVEL statusLamp FOR IGUAL A 1, FAZ
            digitalWrite(pinoRele, HIGH); //DESLIGA O MÓDULO RELÉ (LÂMPADA APAGA)
            statusLamp = 0; //VARIÁVEL RECEBE O VALOR 0
            delay(200); //INTERVALO DE 200 MILISSEGUNDOS
        }
  }
}