
#include <Servo.h>

Servo servo;  

int pos = 0;
const int Botao = 2;
int estadoBotao = LOW;
int lampada = 8;

void setup() {
  servo.attach(6);
  servo.write(pos);  
  pinMode(Botao, INPUT);
  pinMode (lampada, OUTPUT);
  Serial.begin (9600);
}

void loop() {

 estadoBotao = digitalRead(Botao);
  
  if (estadoBotao == HIGH)
  {
   delay(100);
   if (pos < 30)
   {   
   servo.write (90);
   delay (1000);  
   pos = 90;
   digitalWrite (lampada, HIGH);
   Serial.println ("Portão Aberto");
   }
   else
   {
    servo.write (0);
    delay (1000);
    pos = 0;
    digitalWrite (lampada,LOW);
    Serial.println ("Portão Fechado");
   }
 
   
   
  }

}



