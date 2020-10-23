#include "cmqtt.h"
#include "random.h"

void setup() 
{
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  set_wifi();
  setup_Cayenne();
}

void loop() 
{
  Cayenne_loop();
}
