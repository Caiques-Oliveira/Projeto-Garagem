#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>


int lampada = 8;
char portao;



byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xF1, 0xE2 };


void callback(char* topic, byte* payload, unsigned int length)
{

  if (topic == portao)
  {
    if (payload == 1)
    {
      lampada = HIGH;
    }
  }

}
void callback(char* topic, byte* payload, unsigned int length);
EthernetClient ethClient;
PubSubClient client("m12.mqttcloud.com", 14713, callback, ethClient);




void setup()
{
  Ethernet.begin(mac);
  if (client.connect("arduinoClient", "teste", "teste")) {
    //client.publish("outTopic","hello world");
    client.subscribe("inTopic");
  }

  pinMode (lampada, OUTPUT);

}


void loop() {
  client.loop();


}




// put your main code here, to run repeatedly:


