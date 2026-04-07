const int trigPin = 3;
const int echoPin = 4;
const int motorPin = 5;
const int greenPin = 9;
const int bluePin = 10;
const int redPin = 11;

unsigned long slouchStartTime = 0;
bool isSlouching = false;
const int thresholdDistance = 30;
const unsigned long timeLimit = 5000;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  
  Serial.print("Distance : ");
  Serial.println(distance);
  
  if (distance > 0 && distance < thresholdDistance) {
    if (!isSlouching){
      slouchStartTime = millis();
      isSlouching = true;
    }
    if (millis() - slouchStartTime > timeLimit){
      digitalWrite(motorPin, HIGH);
      analogWrite(redPin, 255);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
    }
    else{
      analogWrite(redPin, 0);
      analogWrite(greenPin, 255);
      analogWrite(bluePin, 255);
    }
  }
  else{
    isSlouching = false;
    digitalWrite(motorPin, LOW);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
  }
  delay(100);
}
