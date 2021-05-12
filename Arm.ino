#include <Servo.h>

Servo myservo;
int pos = 0;

void setup(){
  myservo.attach(9);  // kobler servoen paa pin 9 til servo-objektet
}

void loop(){
    glad();
    delay(2000);
    trist();
    delay(2000);
    sint();
    delay(2000);
}

void glad(){
    for (pos = 0; pos <= 180; pos += 1) { // armen gaar opp
        myservo.write(pos);
    }
    delay(1500);
    for (pos = 180; pos >= 0; pos -= 1) { // armen gaar ned
        myservo.write(pos);
    }
}

void sint(){
    for (int i = 0; i < 2; i++) {
        for (pos = 0; pos <= 180; pos += 1) {
            myservo.write(pos);
        }
        delay(300);
        for (pos = 180; pos >= 0; pos -= 1) {
            myservo.write(pos);
        }
        delay(300);             
    } 
}

void trist(){
    for (pos = 0; pos <= 180; pos += 1) {
        myservo.write(pos);
    }
    delay(500);
    for (int i = 0; i < 2; i++) {
        for (pos = 180; pos >= 0; pos -= 1) {
            myservo.write(pos);
        }
        delay(150);
        for (pos = 0; pos <= 180; pos += 1) {
            myservo.write(pos);
        }
        delay(150);
        for (pos = 180; pos >= 0; pos -= 1) {
            myservo.write(pos);
        }   
    }
}
