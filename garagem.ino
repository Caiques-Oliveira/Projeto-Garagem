// Projeto de automacao residencial - Controle de Portao de Garagem
// Grupo = Caique, Rafael, Wesley
// Versao com controle apenas local, falta integrar comando remoto - MQTT
// Data: 20.10.2017

//-----------------------------------------------------------------------------
// Inclusao de bibliotecas
//-----------------------------------------------------------------------------
#include <Servo.h>

//-----------------------------------------------------------------------------
// Declaracao de variaveis
//-----------------------------------------------------------------------------

Servo portao;
int pos = 0;
const int Botao = 2;
int estadoBotao = LOW;
int lampada = 8;
int estadoPortao = LOW; // LOW indica portao fechado, HIGH indica portao aberto
int estadoLampada = LOW; // LOW indica lampada apagada, HIGH indica lampada acesa

char estadoConexao [4] = {'conectado' , 'desconectado' , 'conectando' , 'enviando'}; // MQTT

//-----------------------------------------------------------------------------
// Prototipos de funcao
//-----------------------------------------------------------------------------

 void abrePortao();
 void fechaPortao();
 void acendeLampada();
 void apagaLampada();
 
 int reportaConexao(char state);
 void recebeMensagem();
 void enviaMensagem();
 

//-----------------------------------------------------------------------------
// Inicializacao
//-----------------------------------------------------------------------------
 
void setup() 
{
  portao.attach(6);
  portao.write(pos);  
  pinMode(Botao, INPUT);
  pinMode (lampada, OUTPUT);
  Serial.begin (9600);
}

//-----------------------------------------------------------------------------
// Principal
//-----------------------------------------------------------------------------

void loop()
{

  estadoBotao = digitalRead(Botao);
  
  if (estadoBotao == HIGH)
  {
   delay(100);//debounce
   
   if (pos < 30)
      { 
          abrePortao();
          acendeLampada();             
      }
      
   else if (pos >60)
      {
          fechaPortao();
          apagaLampada();                 
      }   
  }
}

//-----------------------------------------------------------------------------
// Funcoes auxiliares
//-----------------------------------------------------------------------------

 void abrePortao()
 {
    pos = 90; 
    portao.write (pos);
    delay (1000);         
    Serial.println ("Portão Aberto");
    estadoPortao = HIGH;  
 }
 
 void fechaPortao()
 {
    pos = 0;  
    portao.write (pos);
    delay (1000);    
    Serial.println ("Portão Fechado");
    estadoPortao = LOW; 
 }
 
 void acendeLampada()
 {
    digitalWrite (lampada, HIGH);
    Serial.println ("Lampada Acesa");
    estadoLampada = HIGH;  
 }
 
 void apagaLampada()
 {
    digitalWrite (lampada,LOW);
    Serial.println ("Portão Apagada");
    estadoLampada = LOW;  
 }
 
//-----------------------------------------------------------------------------
// EOF
//-----------------------------------------------------------------------------

