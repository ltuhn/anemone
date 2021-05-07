int touch = 3;
int counter = 0; 

void setup() {
  pinMode(3, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, LOW);

}

void loop() {
  unsigned long currentTime = millis(); 

  if (digitalRead(touch) == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH); 
    counter ++; 
  }
  else if (digitalRead(touch) == LOW) {
    digitalWrite(LED_BUILTIN, LOW); 
  }

  delay(100);

  if (counter == 20) {
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000); 
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(1000); 
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000); 

    counter = 0;
  }
}
