# include <avr/sleep.h>
# define interruptPin 2

int touchSensor1 = 2; 
int touchSensor2 = 3;
int screen = 4; 
int piezo = 5;
int sleepButton = 6; 
int potentiometer = 7;

int counter = 0;

String feeling = "neutral"; //kan også bare bruke en int for dette
  
void setup() {
  Serial.begin(9600);
  pinMode(touchSensor1, INPUT);
  pinMode(touchSensor2, INPUT);
  pinMode(sleepButton, INPUT_PULLUP);
  pinMode(screen, OUTPUT);
  pinMode(piezo, OUTPUT);
  
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
    sov();
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
void sov() {
  sleep_enable();
  attachInterrupt(0, vaakneOpp, LOW); // maa noe endres her? 
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  //digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  sleep_cpu();
  //Serial.println("Koden fortsetter noe som betyr at jeg har vaakna opp");
  //digitalWrite(LED_BUILTIN, HIGH); // LED lyser opp for aa vise at den har vaaknet opp, men kan erstatte dette med noe annet
}

void vaakneOpp() {
  //Serial.println("Naa vaakner jeg opp");
  sleep_disable();
  detachInterrupt(0);
}
  
void neutral() {
  //kode for nøytralt ansiktsuttrykk
  //ta ned armer
}
void happy() {
  //kode for glad ansiktsuttrykk og glad lyd
  //bevege armer(?)
}
   
