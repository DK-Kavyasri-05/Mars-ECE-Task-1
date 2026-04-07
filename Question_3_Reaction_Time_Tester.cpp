const int led = 2;
const int button = 9;

unsigned long  start_time;
unsigned long  delay_time;
unsigned long  reaction_time;
unsigned long  prev_time;
int state_led = 0;

void setup(){
  pinMode(led,OUTPUT);
  pinMode(button,INPUT_PULLUP);
  randomSeed(analogRead(A0));
  Serial.begin(9600);
}
void loop(){
  unsigned long curr_time = millis();
  
  if(state_led == 0){
    delay_time = random(2000,5000);
    prev_time = curr_time;
    state_led = 1;
    Serial.println("Started Be Ready");
  }
  else if(state_led == 1){
    if (digitalRead(button) == HIGH){
      prev_time = curr_time;
    }
    
    if(curr_time - prev_time >= delay_time){
      digitalWrite(led, HIGH);
      start_time = curr_time;
      state_led = 2;
    }
  }
  else if(state_led == 2){
    Serial.println("State 2");
    if(digitalRead(button) == HIGH){
      reaction_time = curr_time - start_time;
      
      Serial.print("Reaction Time in ms: ");
      Serial.print(reaction_time);
      Serial.println("ms");
      
      digitalWrite(led, LOW);
      delay(1000);
      state_led = 0;
    }
  }
}    
