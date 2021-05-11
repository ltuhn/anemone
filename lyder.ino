

  #include "pitches.h"

  // Lyddefininsjoner :  
  
 // angrydef
  int angry[] = {NOTE_C3, NOTE_G2, NOTE_F2, NOTE_G2};
  int angryDurations[] = {4, 8, 8, 2};

  int angryto[] = {NOTE_C4, NOTE_G3, NOTE_G3};
  int angrytoDurations[] = {4, 4, 2};

  int angrytre[] = {NOTE_G3, NOTE_G3, NOTE_G3}; 
  int angrytreDurations[] = {2, 2, 2}; 


  // Roboten er mett: 
  int happy[] = {NOTE_G4, NOTE_C4, NOTE_G4, NOTE_B4, NOTE_G4};
  int happyDurations[] = {4, 8, 8, 4, 4};
  

  int happyto[] = {NOTE_AS4, NOTE_G4, NOTE_AS4, NOTE_G4};
  int happytoDur[] = {4, 8, 4, 4};

  int happytre[] = {NOTE_AS5, NOTE_G5};
  int happytreDur[] = {4, 2}; 

 // saddef
  int sad[] = {NOTE_G3, NOTE_C3};
  int sadDurations[] = {2, 2};

  int sadto[] = {NOTE_E3, NOTE_A2, NOTE_C2}; 
  int sadtoDurations[] = {2, 2, 2};

  

// Spiller sint- melodier, tar inn lydpin som argument: 
void playAngry(int pin) {

  int randomnum = random(3); 

  if (randomnum == 0) {
    
     for (int thisNote = 0; thisNote < 4; thisNote++) {

        // to calculate the note duration, take one second divided by the note type.

        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

        int noteDuration = 1000 / angryDurations[thisNote];

        tone(pin, angry[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.

        // the note's duration + 30% seems to work well:

        int pauseBetweenNotes = noteDuration * 1.30;

        delay(pauseBetweenNotes);

        // stop the tone playing:

        noTone(pin);

      }  
  }
  else if (randomnum == 1) {
   
      for (int thisNote = 0; thisNote < 3; thisNote++) {

        // to calculate the note duration, take one second divided by the note type.

        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

        int noteDuration = 1000 / angrytoDurations[thisNote];

        tone(pin, angryto[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.

        // the note's duration + 30% seems to work well:

        int pauseBetweenNotes = noteDuration * 1.30;

        delay(pauseBetweenNotes);

        // stop the tone playing:

        noTone(pin);
    }
  }
  else if (randomnum == 2) {
   
      for (int thisNote = 0; thisNote < 3; thisNote++) {

        // to calculate the note duration, take one second divided by the note type.

        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

        int noteDuration = 1000 / angrytreDurations[thisNote];

        tone(pin, angrytre[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.

        // the note's duration + 30% seems to work well:

        int pauseBetweenNotes = noteDuration * 1.30;

        delay(pauseBetweenNotes);

        // stop the tone playing:

        noTone(pin);
    }
  }
}

// Spiller "Happy"- lyder, tar inn lydpin som argument: 
void playHappy(int pin) {

  int randomnum = random(3);

  // MELODI 1: 
  if (randomnum == 0) {

      // iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 4; thisNote++) {

      // to calculate the note duration, take one second divided by the note type.

      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

      int noteDuration = 1000 / happytoDur[thisNote];

      tone(pin, happyto[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.

      // the note's duration + 30% seems to work well:

      int pauseBetweenNotes = noteDuration * 1.30;

      delay(pauseBetweenNotes);

      // stop the tone playing:

      noTone(pin);

      }
    }

   // MELODI 2: 
   else if (randomnum = 1) {
    
      for (int thisNote = 0; thisNote < 2; thisNote++) {

      // to calculate the note duration, take one second divided by the note type.

      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

      int noteDuration = 1000 / happytreDur[thisNote];

      tone(pin, happytre[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.

      // the note's duration + 30% seems to work well:

      int pauseBetweenNotes = noteDuration * 1.30;

      delay(pauseBetweenNotes);

      // stop the tone playing:

      noTone(pin);

      }
   }
    

}

// Spiller sad- melodi, tar inn lydpin som argument: 
void playSad(int pin) {

  int randomnum = random(2);

  if (randomnum == 0) {
      // iterate over the notes of the melody:
      for (int thisNote = 0; thisNote < 2; thisNote++) {

        // to calculate the note duration, take one second divided by the note type.

        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

        int noteDuration = 1000 / sadDurations[thisNote];

        tone(pin, sad[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.

        // the note's duration + 30% seems to work well:

        int pauseBetweenNotes = noteDuration * 1.30;

        delay(pauseBetweenNotes);

        // stop the tone playing:

        noTone(pin);

      }
    }
  else if(randomnum == 1) {
      // iterate over the notes of the melody:
      for (int thisNote = 0; thisNote < 3; thisNote++) {

        // to calculate the note duration, take one second divided by the note type.

        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

        int noteDuration = 1000 / sadtoDurations[thisNote];

        tone(pin, sadto[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.

        // the note's duration + 30% seems to work well:

        int pauseBetweenNotes = noteDuration * 1.30;

        delay(pauseBetweenNotes);

        // stop the tone playing:

        noTone(pin);

      }
    }
}

// Spiller "Mett", tar inn lydpin som argument: 
void spillMett(int pin) {
  for (int thisNote = 0; thisNote < 5; thisNote++) {

      // to calculate the note duration, take one second divided by the note type.

      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

      int noteDuration = 1000 / happyDurations[thisNote];

      tone(pin, happy[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.

      // the note's duration + 30% seems to work well:

      int pauseBetweenNotes = noteDuration * 1.30;

      delay(pauseBetweenNotes);

      // stop the tone playing:

      noTone(pin);

      }
}
