const int red = 9;
const int blue = 10;
const int green = 11; 
const int led = 8;
const int potentio = A0;

unsigned long int last_time_led = 0;
int state_led = LOW;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(potentio, INPUT); 
  Serial.begin(9600);
}

void loop() {
  unsigned long curr_time = millis();
  int value = analogRead(potentio); 
    
  if ((curr_time - last_time_led) >= value) {
    Serial.println(state_led);
    last_time_led = curr_time;
    state_led = !state_led;
    digitalWrite(led, state_led);
  }
  
  if (value < 341) { 
    analogWrite(red, 255);
    analogWrite(blue, 0);
    analogWrite(green, 0);
  } 
  else if (value >= 341 && value < 682) { 
    analogWrite(red, 0);
    analogWrite(blue, 0);
    analogWrite(green, 255);
  } 
  else { 
    analogWrite(red, 0);
    analogWrite(blue, 255);
    analogWrite(green, 0);
  }
  
}
