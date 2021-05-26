#include "pitches.h"

// Potentiometerpin: 
int potentiometerPin = A0;

// Lydpin: 
int lydPin = 4;
int value = 0;
int metthet = 500;
int mett = 10000;
long currentTime = 0;

// SETUP:
void setup() { 
  pinMode(lydPin, OUTPUT); 
  pinMode(potentiometerPin, INPUT_PULLUP);
  value = map(value, 0, 1023, 0, 255);
}

// Hovedloop: 
void loop(){ 

  long tidsdifferanse = millis() - currentTime; 
  
  // dersom mettheten er over 10, trekk fra 5. sekund
  if (tidsdifferanse > 5000) {
    currentTime = millis(); 
    
    if (metthet > 0) {
      metthet = metthet - 50;
    }
    
  }

   
   // leser verdi fra potentiometeret: 
   int potStartpunkt = analogRead(potentiometerPin);
   
    // dersom dyret er mett:
   if (metthet >= mett) {
      spillMett(lydPin); 
   }
    // dersom dyret er skrubbsulten: 
   if (metthet <= 1) {
      metthet = 200;
      playAngry(lydPin);
   }

    
    /* Her skal differansen i potentiometer, både positiv og negativ, legges til på mettheten: 
   vi starter med å se etter forskjeller i potentiometeret: */
   int potentiometerread = analogRead(potentiometerPin); 
   int differanse;
   boolean positiv = (potentiometerread - potStartpunkt) > 0;
   
   // dersom det er positiv endring i potentiometer: 
   if (positiv) {
      differanse = (potentiometerread - potStartpunkt) / 2; 
   }
    // dersom potentiometeret ikke har endret seg:
   else if (potentiometerread == potStartpunkt) {
      return;
   }
    // dersom det er negativ endring i potentiometer: 
   else if (!positiv) {
      differanse = (potStartpunkt - potentiometerread) / 2; 
   }

   // dersom mettheten ikke er over det høyeste nivået, vil vi legge til denne differansen: 
   if (metthet < mett) {
     if (differanse > 5) {
        if (differanse + metthet > mett) {
          metthet = mett; 
          return; 
          }
        metthet = metthet + differanse; 
      }
        
   }
}
