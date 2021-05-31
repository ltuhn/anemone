#include <Servo.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


Servo arm1;
Servo arm2;
int pos1 = 0;
int pos2 = 180;
int touchSensor1 = 7; 
int touchSensor2 = 8;
int potentiometer = 0;
int speaker = 5;
int metthet = 1000; 
int maksMetthet = 30000; 
int counter = 0;
//int sintLED = 4;
//int gladLED = 3;
//int tristLED = 2; 
long currentTime = millis();
long naavaerendeTid = 0;
int potStartpunkt;
String forrigeFolelse;
int andreArduino; 

String feeling = "neutral"; //kan også bare bruke en int for dette
  
void setup() {
  Serial.begin(9600);
  pinMode(touchSensor1, INPUT);
  pinMode(touchSensor2, INPUT);
  pinMode(potentiometer, INPUT_PULLUP);
  pinMode(speaker, OUTPUT);
  //pinMode(sintLED, OUTPUT);
  //pinMode(gladLED, OUTPUT);
  //pinMode(tristLED, OUTPUT);
  arm1.attach(6);
  arm2.attach(9); // TEST
  potStartpunkt = analogRead(potentiometer);
  arm1.write(pos1);
  arm2.write(pos2);
  andreArduino = analogRead(A1);
}

void loop() {
//  int touchState1 = digitalRead(touchSensor1);
//  int touchState2 = digitalRead(touchSensor2);
//  int potentiometerState = analogRead(potentiometer);
//  metthetsKontroll();
//  checkFeeling(); 
//  
//    if (touchState1 == HIGH || touchState2 == HIGH) {
//    petting();
//    }

  happy_feeling();
  delay(1000);
  angry_feeling();
  delay(1000);
}

void checkFeeling() {
  if (forrigeFolelse.equalsIgnoreCase(feeling)) {
    return;  
  }
  if (feeling.equalsIgnoreCase("neutral")) { //er ikke helt sikker på om equalsIgnoreCase() fungerer likt som java i Arduino IDE
    Serial.print("fant ut nøytral");
    neutral_feeling();
    forrigeFolelse = "neutral";
  } else if (feeling.equalsIgnoreCase("happy")) {
    Serial.print("fant ut glad");
    happy_feeling();
    forrigeFolelse = "happy";
  } else if (feeling.equalsIgnoreCase("angry")) {
    Serial.print("fant ut sint");
    angry_feeling();
    forrigeFolelse = "angry";
  } else if (feeling.equalsIgnoreCase("sad")) {
    Serial.print("fant ut trist");
    sad_feeling();
    forrigeFolelse = "sad";
  }
}

void petting() {
  Serial.print("klapper");
  long timeSincePet = currentTime - millis(); 
  
  if (timeSincePet > 9999) {
    counter = 0;
  }
  if (counter >= 100) {
    feeling = "angry";
  } 
  else {
    feeling = "happy";
    counter++;
  }
}

void metthetsKontroll() {
  Serial.print("mett\n");
  long tidsdifferanse = millis() - naavaerendeTid; 
  // dersom mettheten er over 10, trekk fra 5. sekund
  if (tidsdifferanse > 5000) {
      naavaerendeTid = millis(); 
      if (metthet > 0) {
        metthet = metthet - 50;
      } 
  }
  Serial.println(metthet);
   // leser verdi fra potentiometeret: 
    // dersom dyret er mett:
   if (metthet >= maksMetthet) {
      feeling = "happy"; 
      spillMett(speaker);   
   }
    // dersom dyret er skrubbsulten: 
   if (metthet <= 1) {
      metthet = 200;
      feeling = "angry";
      playAngry(speaker);
   }
    /* Her skal differansen i potentiometer, både positiv og negativ, legges til på mettheten: 
   vi starter med å se etter forskjeller i potentiometeret: */
   int potentiometerSluttpunkt = analogRead(potentiometer);
   int differanse;
   boolean erPositiv = (potentiometerSluttpunkt - potStartpunkt) > 0;
   // dersom det er positiv endring i potentiometer: 
   if (erPositiv) {
      differanse = (potentiometerSluttpunkt - potStartpunkt); 
      potStartpunkt = potentiometerSluttpunkt; // ****
   }
    // dersom potentiometeret ikke har endret seg:
   else if (potentiometerSluttpunkt == potStartpunkt) {
      return;
   }
    // dersom det er negativ endring i potentiometer: 
   else if (!erPositiv) {
      differanse = (potStartpunkt - potentiometerSluttpunkt);
      potStartpunkt = potentiometerSluttpunkt; // ****
   }

   // dersom mettheten ikke er over det høyeste nivået, vil vi legge til denne differansen: 
   if (metthet < maksMetthet) {
     if (differanse > 5) {
        if (differanse + metthet > maksMetthet) {
            metthet = maksMetthet; 
            return; 
            }
        metthet = metthet + differanse; 
     }
        
   }
}
    
void neutral_feeling() {
  Serial.print("er nøytral");
  analogWrite(andreArduino, 900); 
  //kode for nøytralt ansiktsuttrykk
//  skjerm_oynene.begin(SSD1306_SWITCHCAPVCC, 0x3C);
//  skjerm_oynene.clearDisplay();
//  skjerm_oynene.drawBitmap(0, 0, vanlig, 128, 64, WHITE);
//  skjerm_oynene.display();
  //ta ned armer
}

void happy_feeling() {
  Serial.print("er glad");
  analogWrite(andreArduino, 100); 
  // led
  //digitalWrite(tristLED, LOW);
  //digitalWrite(sintLED, LOW);
  //digitalWrite(gladLED, HIGH);
  //kode for glad ansiktsuttrykk og glad lyd
// skjerm_oynene.begin(SSD1306_SWITCHCAPVCC, 0x3C);
//  skjerm_oynene.clearDisplay();
//  skjerm_oynene.drawBitmap(0, 0, glad, 128, 64, WHITE);
//  skjerm_oynene.display();
  //armer
//  for (pos1 = 0; pos1 <= 180; pos1 += 1) { // armen gaar opp
//      arm1.write(pos1);
//  }
//  for (pos2 = 0; pos2 <= 180; pos2 += 1) { // armen gaar opp, -
//      arm2.write(pos2);
//  }
//  delay(1500);
//  for (pos1 = 180; pos1 >= 0; pos1 += 1) { // armen gaar ned, -
//      arm1.write(pos1);
//  }
//  for (pos2 = 180; pos2 >= 0; pos2 += 1) { // armen gaar ned, +
//      arm2.write(pos2);
//  }

  arm1.write(30);
  arm2.write(150);
  delay(1500);
  arm1.write(0);
  arm2.write(180);
}

void sad_feeling() {
  Serial.print("er trist");
  analogWrite(andreArduino, 700); 
  // led
  //digitalWrite(sintLED, LOW);
  //digitalWrite(gladLED, LOW);
  //digitalWrite(tristLED, HIGH);
  // skjerm
//  skjerm_oynene.begin(SSD1306_SWITCHCAPVCC, 0x3C);
//  skjerm_oynene.clearDisplay();
//  skjerm_oynene.drawBitmap(0, 0, trist, 128, 64, WHITE);
//  skjerm_oynene.display();
  //armer
  arm1.write(20);
  arm2.write(160);
  delay(100);
  arm1.write(0);
  arm2.write(180);
  delay(100);
  arm1.write(20);
  arm2.write(160);
  delay(100);
  arm1.write(0);
  arm2.write(180);
}

void angry_feeling() {
  Serial.print("er sur");
  analogWrite(andreArduino, 450); 
  // led
  //digitalWrite(gladLED, LOW);
  //digitalWrite(tristLED, LOW);
  //digitalWrite(sintLED, HIGH);
  // skjerm
//  skjerm_oynene.begin(SSD1306_SWITCHCAPVCC, 0x3C);
//  skjerm_oynene.clearDisplay();
//  skjerm_oynene.drawBitmap(0, 0, sint, 128, 64, WHITE);
//  skjerm_oynene.display();
  //armer
//  for (pos1 = 0; pos1 <= 180; pos1 += 1) { // armen gaar opp
//      arm1.write(pos1);
//  }
//  for (pos2 = 0; pos2 <= 180; pos2 -= 1) { // armen gaar opp
//      arm2.write(pos2);
//  }
//  delay(100);
//  for (pos1 = 180; pos1 >= 0; pos1 -= 1) { // armen gaar ned
//      arm1.write(pos1);
//  }
//  for (pos2 = 180; pos2 >= 0; pos2 += 1) { // armen gaar ned
//      arm2.write(pos2);
//  }
//  delay(100);
//  for (pos1 = 0; pos1 <= 180; pos1 += 1) { // armen gaar opp
//      arm1.write(pos1);
//  }
//  for (pos2 = 0; pos2 <= 180; pos2 -= 1) { // armen gaar opp
//      arm2.write(pos2);
//  }
//  delay(100);
//  for (pos1 = 180; pos1 >= 0; pos1 -= 1) { // armen gaar ned
//      arm1.write(pos1);
//  }
//  for (pos2 = 180; pos2 >= 0; pos2 += 1) { // armen gaar ned
//      arm2.write(pos2);
//  }

  arm1.write(180);
  arm2.write(0);
  delay(100);
  arm1.write(0);
  arm2.write(180);
  delay(100);
  arm1.write(180);
  arm2.write(0);
  delay(100);
  arm1.write(180);
  arm2.write(0);
}
