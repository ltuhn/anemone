# include <avr/sleep.h>
# define interruptPin 2

void setup(){
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  digitalWrite(LED_BUILTIN, HIGH); // kun for aa indikere om Arduino-en sover eller ikke, men denne kan vi endre paa
 }

 void loop(){
  Serial.println("sleep");
  sov();
  Serial.println("aaa"); // Dukker ikke opp hvis Arduinoen sover
  }

  void sov(){
    sleep_enable();
    attachInterrupt(0, vaakneOpp, LOW);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
    sleep_cpu();
    Serial.println("God morgen, naa sover jeg ikke lenger");
    digitalWrite(LED_BUILTIN, HIGH);
  }

  void vaakneOpp(){
    Serial.println("satte paa interrupt");
    sleep_disable();
    detachInterrupt(0);
    }
