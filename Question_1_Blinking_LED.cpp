const int led1=2;
const int led2=3;
const int led3=5;

int state_1=LOW;
int state_2=LOW;
int state_3=LOW;

unsigned long int lasttime_1=0;
unsigned long int lasttime_2=0;
unsigned long int lasttime_3=0;

const long interval_1=500;
const long interval_2=1000;
const long interval_3=1500;

void setup(){
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  
}

void loop(){
  unsigned long int currtime=millis();
  
  
  if((currtime-lasttime_1)>=interval_1){
    lasttime_1 = currtime;
    state_1=!state_1;
    digitalWrite(led1,state_1);
  }
  if((currtime-lasttime_2)>=interval_2){
    lasttime_2 = currtime;
    state_2=!state_2;
    digitalWrite(led2,state_2);
  }
  if((currtime-lasttime_3)>=interval_3){
    lasttime_3 = currtime;
    state_3=!state_3;
    digitalWrite(led3,state_3);
  }
}
