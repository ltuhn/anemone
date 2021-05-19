#include <Servo.h>

Servo arm;
int pos = 0;
int touchSensor1 = 2; 
int touchSensor2 = 3;
int screen = 4; 
int piezo = 5;
int sleepButton = 6; 
int potentiometer = 7;

int counter = 0;

String feeling = "neutral"; //kan også bare bruke en int for dette
  
void setup() {
  pinMode(touchSensor1, INPUT);
  pinMode(touchSensor2, INPUT);
  pinMode(sleepButton, INPUT_PULLUP);
  pinMode(screen, OUTPUT);
  pinMode(piezo, OUTPUT);
  arm.attach(9);
  
  currentTime = millis();
}

void loop() {
  int touchState1 = digitalRead(touchSensor1);
  int touchState2 = digitalRead(touchSensor2);
  int buttonState = digitalRead(sleepButton);
  
  checkFeeling(); 
  
  if (touchState1 == HIGH or touchState2 == HIGH) {
    petting();
  }
  if (buttonState == LOW) {
    //sleep
  }
  //osv. 
}

String checkFeeling() {
  if (feeling.equalsIgnoreCase("neutral")) { //er ikke helt sikker på om equalsIgnoreCase() fungerer likt som java i Arduino IDE
    neutral();
  }
  if (feeling.equalsIgnoreCase("happy")) {
    happy();
  }
  if (feeling.equalsIgnoreCase("bored")) {
    //osv. 
  }
}

void petting() {
  timeSincePet = currentTime - millis(); 
  
  if (timeSincePet > 9999) {
    counter = 0;
  }
  if (counter >= 20) {
    feeling = "angry";
  } 
  else {
    feeling = "happy";
    counter++;
  }
}
    
void neutral() {
  //kode for nøytralt ansiktsuttrykk
  //ta ned armer
}
void happy() {
  //kode for glad ansiktsuttrykk og glad lyd
  //bevege armer
  for (pos = 0; pos <= 180; pos += 1) { // armen gaar opp
      myservo.write(pos);
  }
  delay(1500);
  for (pos = 180; pos >= 0; pos -= 1) { // armen gaar ned
      myservo.write(pos);
  }
}

void sad() {

}

void angry() {

}
   
