int touchSensor1 = 2; 
int touchSensor2 = 3;
int screen = 4; 
int piezo = 5;

String feeling = "neutral"; 
  
void setup() {
  pinMode(touchSensor1, INPUT);
  pinMode(touchSensor2, INPUT);
  pinMode(screen, OUTPUT);
  pinMode(piezo, OUTPUT);
}

void loop() {
  int touchState1 = digitalRead(touchSensor1);
  int touchState2 = digitalRead(touchSensor2);
  
  checkFeeling(); 
  
  if (touchState1 == HIGH or touchState2 == HIGH) {
    feeling = "happy"; 
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

void neutral() {
  //kode for nøytralt ansiktsuttrykk
  //ta ned armer
}
void happy() {
  //kode for glad ansiktsuttrykk og glad lyd
  //bevege armer(?)
}
   
