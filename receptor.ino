#include <Arduino.h>
#include "heltec.h"
#define BAND 915E6  //PODENDO ASSUMIR OS VALORES DE 868E6,915E6,433E6
String rssi = "RSSI --"; //FORÇA DO SINAL
String packSize = "--";
String packet; //VAI RECEBER O TAMNHO DO PACOTE

void loop() {
 int packetSize = LoRa.parsePacket();//FUNÇÃO QUE VERIFICA SE O PACOTE TEM O TAMANHO MINIMO DE CARACTERES
 if (packetSize)
 cbk(packetSize); //CHAMA A FUNÇÃO CBK
 delay(10); 
}

void LoRaData(){
 Heltec.display->clear(); //LIMPA O DISPLAY
 Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT); //ALINHAMENTO DO TEXTO
 Heltec.display->setFont(ArialMT_Plain_10); //FONTE USADA
 Heltec.display->drawString(0 , 15 , "Received " + packSize + " bytes"); //apenas em 1.4.4.1
 Heltec.display->drawString(0, 0, rssi); // PRINTA A FORÇA DO SINAL
 Heltec.display->drawString(0, 30, packet); // PRINTA OS DADOS RECEBIDOS
 Heltec.display->display(); //MOSTRA O QUE FOI CONFIGURADO
}

void cbk(int packetSize){
 packet = "";
 packSize = String(packetSize,DEC);
 for (int i = 0; i < packetSize; i++)
 packet += (char) LoRa.read();
 rssi = "RSSI " + String(LoRa.packetRssi(), DEC);
 LoRaData();
}


void setup() {
 Heltec.begin(true /*Habilita o Display*/, true /*Heltec.Heltec.Heltec.LoRa Disable*/, true /*Habilita debug Serial*/, true /*Habilita o PABOOST*/, BAND /*Frequência BAND*/); //CONFIGURANDO O HELTEC
 Heltec.display->init(); //Inicia o display
 Heltec.display->flipScreenVertically(); //GIRA A TELA
 Heltec.display->setFont(ArialMT_Plain_10); //FONTE
 delay(1500);
 Heltec.display->clear(); //LIMPA A TELA

 Heltec.display->drawString(0, 0, "LoRa iniciado com sucesso!");
 Heltec.display->drawString(0, 10, "Esperando dados...");
 Heltec.display->display(); //MOSTRA OS DADOS
 delay(1000);
 //LoRa.onReceive(cbk);
 LoRa.receive(); //RECEBE OS DADOS
 }
 
