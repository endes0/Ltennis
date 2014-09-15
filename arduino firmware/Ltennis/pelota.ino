#include <Servo.h>

Servo myservo;

void start2() {
  myservo.attach(9);
}

void openP(char espera, char pelotas) {
  int esp = espera * 1000;
for (int x = -1; x < pelotas; x++) {
  myservo.write(90);
  delay(500);
  myservo.write(0);
  delay(esp); 
  }
  
}

