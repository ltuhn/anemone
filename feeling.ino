int touchSensor1 = 2; 
int touchSensor2 = 3;
int screen = 4; 
int piezo = 5;
int counter = 0;

String feeling = "neutral"; //kan også bare bruke en int for dette
  
void setup() {
  pinMode(touchSensor1, INPUT);
  pinMode(touchSensor2, INPUT);
  pinMode(screen, OUTPUT);
  pinMode(piezo, OUTPUT);
  currentTime = millis();
}

void loop() {
  int touchState1 = digitalRead(touchSensor1);
  int touchState2 = digitalRead(touchSensor2);
  
  checkFeeling(); 
  
  if (touchState1 == HIGH or touchState2 == HIGH) {
    petting();
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
  //bevege armer(?)
}
   
