#include <Servo.h>
#include <SPI.h>
#include <Wire.h>

Servo arm1;
Servo arm2;
int pos1 = 0;
int pos2 = 180;
int touchSensor1 = 7; 
int touchSensor2 = 8;
int potentiometer = 0;
int speaker = 5;
int metthet = 1000; 
int maksMetthet = 10000; 
int counter = 0;
int sintLED = 4; //rød
int gladLED = 3; //grønn
int tristLED = 2; //blå
long currentTime = millis();
long naavaerendeTid = 0;
int potStartpunkt;
String forrigeFolelse;

String feeling = "neutral"; //begynner i nøytral
  
void setup() {
  Serial.begin(9600);
  pinMode(touchSensor1, INPUT);
  pinMode(touchSensor2, INPUT);
  pinMode(potentiometer, INPUT_PULLUP);
  pinMode(speaker, OUTPUT);
  pinMode(sintLED, OUTPUT);
  pinMode(gladLED, OUTPUT);
  pinMode(tristLED, OUTPUT);
  arm1.attach(6);
  arm2.attach(9);
  potStartpunkt = analogRead(potentiometer);
  arm1.write(pos1);
  arm2.write(pos2);
}

void loop() {
  int touchState1 = digitalRead(touchSensor1);
  int touchState2 = digitalRead(touchSensor2);
  int potentiometerState = analogRead(potentiometer);
  
  metthetsKontroll();
  checkFeeling(); //sjekker konstant om følelsen er oppdatert
    if (touchState1 == HIGH || touchState2 == HIGH) {
    petting();
    }

}

void checkFeeling() {
  if (forrigeFolelse.equalsIgnoreCase(feeling)) { //sjekker om forrige følelse er samme som nåværende for å hindre gjentakelse 
    return;  
  }
  if (feeling.equalsIgnoreCase("neutral")) { 
    Serial.println("fant ut nøytral");
    neutral_feeling();
    forrigeFolelse = "neutral";
  } else if (feeling.equalsIgnoreCase("happy")) {
    Serial.println("fant ut glad");
    happy_feeling();
    forrigeFolelse = "happy";
  } else if (feeling.equalsIgnoreCase("angry")) {
    Serial.println("fant ut sint");
    angry_feeling();
    forrigeFolelse = "angry";
  } else if (feeling.equalsIgnoreCase("sad")) {
    Serial.println("fant ut trist");
    sad_feeling();
    forrigeFolelse = "sad";
  }
}

void petting() {
  Serial.println("klapper");
  long timeSincePet = currentTime - millis(); 
  
  if (timeSincePet > 9999) { //telleren blir resett
    counter = 0;
  }
  if (counter >= 100) {
    feeling = "sad";
  } 
  else if (counter < 1000 || counter >= 90) {
    feeling = "happy";
    counter++;
  }
}

void metthetsKontroll() {
  long tidsdifferanse = millis() - naavaerendeTid; 
  // dersom mettheten er over 0, trekk fra 5. sekund
  if (tidsdifferanse > 5000) {
      naavaerendeTid = millis(); 
      if (metthet > 0) { // 0
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
   int differanse = potentiometerSluttpunkt - potStartpunkt; 
   boolean erPositiv = false;
   boolean erNegativ = false; 
   if (differanse > 35) {
    erPositiv = true; 
   }
   else if (differanse < -35) {
    erNegativ = true; 
   }
   else {
    return; 
   }
   // dersom det er positiv endring i potentiometer: 
   if (erPositiv) {
      potStartpunkt = potentiometerSluttpunkt; // ****
   }
   if (erNegativ) {
    potStartpunkt = potentiometerSluttpunkt; // ****
    differanse = 0 - differanse; 
   }
   differanse = differanse / 2; 
    // dersom potentiometeret ikke har endret seg:
    // dersom det er negativ endring i potentiometer: 

   // dersom mettheten ikke er over det høyeste nivået, vil vi legge til denne differansen: 
   if (metthet < maksMetthet) { 
     if (differanse > 5) {
//        Serial.println("Oker metthet linje 142");
        if (differanse + metthet > maksMetthet) {
            metthet = maksMetthet - 50; 
            return; 
            }
        metthet = metthet + differanse; 
     }      
   }
}
    
void neutral_feeling() {
  Serial.println("er nøytral");
  arm1.write(0);
  arm2.write(180);
  //kode for nøytralt ansikusuttrykk
//  skjerm_oynene.begin(SSD1306_SWITCHCAPVCC, 0x3C);
//  skjerm_oynene.clearDisplay();
//  skjerm_oynene.drawBitmap(0, 0, vanlig, 128, 64, WHITE);
//  skjerm_oynene.display();
  //ta ned armer
}

void happy_feeling() {
  Serial.println("er glad");
  // led
  digitalWrite(tristLED, LOW);
  digitalWrite(sintLED, LOW);
  digitalWrite(gladLED, HIGH);
  playHappy(5); //spiller lyd for glad (disse metodene ligger i lyder.ino)

  Serial.println("naa skal armene bevege seg HAPPY");
  //beveger armer
  arm1.write(0);
  arm2.write(180);
  delay(800);
  arm1.write(170);
  arm2.write(10);
  delay(1000);
  arm1.write(0);
  arm2.write(180);
}

void sad_feeling() {
  Serial.println("er trist");
  // led
  digitalWrite(sintLED, LOW);
  digitalWrite(gladLED, LOW);
  digitalWrite(tristLED, HIGH);
  playSad(5); //spiller lyd for trist 
  arm1.write(0);
  arm2.write(180);
  delay(800);
  //beveger armer
  arm1.write(160);
  arm2.write(20);
  delay(500);
  arm1.write(0);
  arm2.write(180);
  delay(1000);
  arm1.write(160);
  arm2.write(20);
  delay(500);
  arm1.write(0);
  arm2.write(180);
}

void angry_feeling() {
  Serial.print("er sur");
  // led
  digitalWrite(gladLED, LOW);
  digitalWrite(tristLED, LOW);
  digitalWrite(sintLED, HIGH);
  playAngry(5); //spiller lyd for sint
 
  arm1.write(0);
  arm2.write(180);
  delay(800);
  //armer
  arm1.write(180);
  arm2.write(0);
  delay(1000);
  arm1.write(0);
  arm2.write(180);
  delay(1000);
  arm1.write(180);
  arm2.write(0);
  delay(1000);
  arm1.write(180);
  arm2.write(0);
}
