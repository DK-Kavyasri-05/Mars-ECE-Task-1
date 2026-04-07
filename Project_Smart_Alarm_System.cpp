const int ldrPin = A0;
const int tiltPin = 2;
const int buzzerPin = 8;
const int snoozeButton = 9;

int lightThreshold = 600;
bool isSnoozed = false;
unsigned long snoozeTime = 0;
const unsigned long snoozeDuration = 10000;

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(tiltPin, INPUT_PULLUP);
  pinMode(snoozeButton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  int lightLevel = analogRead(ldrPin);
  int tiltState = digitalRead(tiltPin);
  
  Serial.print("Light : ");
  Serial.println(lightLevel);
  
  if (isSnoozed){
    if (millis() - snoozeTime > snoozeDuration){
      isSnoozed = false;
    }
  }
  
  if (lightLevel > lightThreshold && tiltState == LOW && !isSnoozed){
    tone(buzzerPin, 1000);
    
    if (digitalRead(snoozeButton) == LOW){
      noTone(buzzerPin);
      isSnoozed = true;
      snoozeTime = millis();
      delay(500);
    }
  }
  else{
    noTone(buzzerPin);
  }
  delay(100);
}
