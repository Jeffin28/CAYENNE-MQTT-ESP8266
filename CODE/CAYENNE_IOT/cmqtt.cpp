#include <CayenneMQTTESP8266.h>
#include "cmqtt.h"
#include "global.h"

/*++++++++++++Structure obj declaration++++++++++++++*/
Channel Channl;
Device  dev;
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*+++++++++++++++pointer declaration+++++++++++++++++*/
const char* p;
const char* q; 
const char* r; 
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*+++++++++++++++myDevice_credentils+++++++++++++++++*/
const char *username = "YOUR MQTT USERNAME";
const char *password = "YOUR MQTT PASSWORD";
const char *clientID = "YOUR CLIENT ID";
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*++++++++++++++++Function declaration++++++++++++++++*/
void Mqtt_status(int value);
void Cayenne_loop(void);
void setup_Cayenne(void);
void Channel_one_receive(void);
void Channel_two_receive(void);
void Channel_three_receive(void);
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/
 
/*++++++++++++To setup cayenne MQTT++++++++++++++++++*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/
void setup_Cayenne(void)
{
  #ifdef NO_WIFI_INIT
   Cayenne.begin(username, password,clientID,WLAN_SSID,WLAN_PASS);
  #else 
   Cayenne.begin(username, password,clientID);
  #endif 
  Mqtt_status(error);
  memset(&Channl,0,sizeof(Channl));
  memset(&dev,0,sizeof(dev));
}
/*++++++++Cayenne mqtt connection status+++++++++++++*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/
void Mqtt_status(int value)
{
  switch(value)
  {
    case  MQTT_BUFFER_OVERFLOW : Serial.println("Cayenne buffer overflow");
                                 break;
    
    case  MQTT_FAILURE         : Serial.println("Cayenne cconnection failed !!!");
                                 break;
                                 
    case  MQTT_SUCCESS         : Serial.println("Cayenne successfully connected");
                                 break; 
  }
}
/*+++++++++++++++Cayenne callback++++++++++++++++++++*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/
void Cayenne_loop(void) 
{
  Cayenne.loop();
}
/*++++++++++++++++OUT HANDLERS+++++++++++++++++++++++*/
/*++++++++++++++++ CHANNEL 0 ++++++++++++++++++++++++*/
CAYENNE_OUT(0)
{
  Cayenne.virtualWrite(0,dev.device1,TYPE_DIGITAL_SENSOR,UNIT_DIGITAL);
}
/*++++++++++++++++ CHANNEL 1 ++++++++++++++++++++++++*/
CAYENNE_OUT(1)
{
  Cayenne.digitalSensorWrite(1,dev.device2); 
}
/*++++++++++++++++ CHANNEL 2 ++++++++++++++++++++++++*/
CAYENNE_OUT(2)
{
  Cayenne.digitalSensorWrite(2,dev.device3); 
}
/*+++++++++++++++IN HANDLERS+++++++++++++++++++++++++*/
/*++++++++++++++++ CHANNEL 0 ++++++++++++++++++++++++*/
CAYENNE_IN(0)
{
  CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
  Channl.ch1=request.channel;
  p=getValue.asString();
  Channel_one_receive(); 
}
/*++++++++++++++++ CHANNEL 1 ++++++++++++++++++++++++*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/
CAYENNE_IN(1)
{
  CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
  Channl.ch2=request.channel;
  q=getValue.asString();
  Channel_two_receive();
}
/*++++++++++++++++ CHANNEL 2 ++++++++++++++++++++++++*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/
CAYENNE_IN(2)
{
  CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
  Channl.ch3=request.channel;
  r=getValue.asString();
  Channel_three_receive();
}
/*++++++++++ For first channel recieve.++++++++++++++*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/
void Channel_one_receive(void)
{
  dev.device1 = 0;
  dev.device1=atoi(p); 
  Serial.printf("Channel %d, Data %d\n",Channl.ch1,dev.device1);
}
/*++++++++++ For Second channel recieve.+++++++++++++*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/
void Channel_two_receive(void) 
{
  dev.device2= 0;
  dev.device2=atoi(q); 
  Serial.printf("Channel %d, Data %d\n",Channl.ch2,dev.device2);
}
/*++++++++++ For Third channel recieve.++++++++++++++*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/
void Channel_three_receive(void)
{
  dev.device3 = 0;
  dev.device3=atoi(r); 
  Serial.printf("Channel %d, Data %d\n",Channl.ch3,dev.device3);
}
