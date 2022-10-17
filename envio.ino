#include <Arduino.h>
#include "heltec.h"
#define BAND 915E6

String rssi = "RSSI --";
String packSize = "--";
String packet ;

void setup(){
Serial.begin(9600);
Heltec.begin(false, true, true, true, BAND);
}

void loop(){
 LoRa.beginPacket(); //COMECA A ESCREVER O PACOTE 
 LoRa.println("Hello World");
 LoRa.endPacket();//TERMINA DE ESCREVER O PACOTE
}
