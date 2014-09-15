#include <SoftwareSerial.h>
#include <Ardumoto.h>
#include <pelota>
String datosL;
Ardumoto motor;
void setup()  
{  
   Serial.begin(57600);
   Serial.println("Ltennis iniciado correctamente. version 1.0"); 
    start2();
} 

void loop()
{
while (Serial.available()) {
   char c = Serial.read();
   datosL += c;
   }
  
  if (datosL.length() >0) {
    motor.setSpeed('A', motor1p());
    motor.setSpeed('B', motor2p());
    openP(inter(), pelotas());
    motor.stop('A');
    motor.stop('B');
    }
  }
    
int motor1p() {
   String motor1;
   if (datosL.length() >0) {
   motor1 = datosL.substring(0, 2);   
   }  
return motor1.toInt();
}

int motor2p() {
   String motor2;
   if (datosL.length() >0) {
   motor2 = datosL.substring(2, 4);   
   }  
return motor2.toInt();
}

int pelotas() {
   String pelotas;
   if (datosL.length() >0) {
   pelotas = datosL.substring(4, 7);   
   }  
return pelotas.toInt();
}

int inter() {
   String inter;
   if (datosL.length() >0) {
   inter = datosL.substring(7, 9);   
   }  
return inter.toInt();
}

