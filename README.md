# CAYENNE IOT WITH ESP8266
## Overview

<p align="center">
  <img src="IMG/download.png" width="400" align="center">
</p 

The Cayenne MQTT Arduino Library is a collection of code, known as sketch files, that makes it easy for you to connect and send data to and from sensors, actuators, and devices connected to Arduino boards. Cayenne sketch files can be combined with other sketch files for your IoT projects. In this section, we will walk you through configuring the Arduino IDE to use the library and make `publish` and `subscribe` happen.

I have used an actuator system here. All things related to my demonstration are described in the documentation. You can see my concept below :

<p align="center">
  <img src="IMG/concept.png" width="290" align="center">
</p
  
* The system consists of three gadgets like a **LED**,**BULB**,and **FAN** in the `Cayenne` dashboard.Which sends its digital values to ESP8266 via **MQTT**.

## Software
* [Arduino IDE](https://www.arduino.cc/en/Main/Software) for Windows, Linux or Mac OS.

## Steps :
 1. **Download** the repo.
 
 2. For those who don't have a cayenne dashboard 😇 download the ***CAYENNE IOT WITH ESP8266*** named pdf from the **DOC** folder and carefully read it. 
    Create a dashboard with at least one gadget and make simulation possible with **ESP8266**.Create your Cayenne account at https://www.cayenne-mydevices.com.
   
 3. Open **LIB** folder then place the `CayenneMQTT`(version 1.3.0) folders into your arduino local dierectory folder (libraries) from the downloaded repo.Place this library         from my repo or you can download the library from the arduino library manager.
    <p><br>
    
    ***Attention !!*** : If you download the library from `arduino library manager`you should comment one of the function in source code.<br> 
    Open **cmqtt.cpp** and comment :
    
<p align="center">
  <img src="IMG/Screenshot%20(83).png" width="700" align="center">
</p
  
<p align="center"><p align="center">

<p><br>
  
<div align="center">
  
Better use my library 👍 from the **LIB** folder because I have included some changes in the cayenne library for knowing the cayenne MQTT `connection status` and its serial print acknowledgment in Arduino IDE like below picture.It will really help us to know whether the ESP8266 connected or not to **Cayenne** dashboard. 

</div>

<p><br>

<p align="center">
  <img src="IMG/Screenshot%20(81).png" width="700" align="center">
</p
  
<p><br>  
  
* If you go for direct library download you ***gonna miss*** this acknowledgment. But there is no issue with working on the source code. 

## Compatibility
This library was tested with the NodeMCU V1.0 ESP8266  development board. It should also work with other standard ESP8266 that are compatible with the Arduino IDE.
ESP8266 core version that I have tested is `2.4.2` 

## Working 
Demonstration of `publish` and `subscribe` between **ESP8266** and **Cayenne** dashboard described in the documentation from ***page No:7*** onwards and good luck!!!✌️.
