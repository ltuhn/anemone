# include <avr/sleep.h>
# define interruptPin 2

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  digitalWrite(LED_BUILTIN, HIGH); // kun for aa indikere om Arduino-en sover eller ikke, men denne kan vi endre paa
}

void loop() {
  Serial.println("sleep");
  sov();
  Serial.println("aaa"); // Dukker ikke opp hvis Arduinoen sover
}

void sov() {
  sleep_enable();
  attachInterrupt(0, vaakneOpp, LOW);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  sleep_cpu();
  Serial.println("Koden fortsetter noe som betyr at jeg har vaakna opp");
  digitalWrite(LED_BUILTIN, HIGH); // LED lyser opp for aa vise at den har vaaknet opp, men kan erstatte dette med noe annet
}

void vaakneOpp() {
  Serial.println("Naa vaakner jeg opp");
  sleep_disable();
  detachInterrupt(0);
}
