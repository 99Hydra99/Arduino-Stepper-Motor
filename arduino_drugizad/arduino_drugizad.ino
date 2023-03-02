#include <Stepper.h>

int pushButton = 2;
volatile int state = LOW;

// Defines the number of steps per rotation
volatile int stepsPerRevolution = 0;

Stepper myStepper = Stepper(2038, 8, 10, 9, 11);

void setup() {
  pinMode(pushButton, INPUT);
  attachInterrupt(digitalPinToInterrupt(pushButton), nekaj, CHANGE);
  Serial.begin(9600);
}

void loop() {
  myStepper.setSpeed(5);
  myStepper.step(10);
}

void nekaj() {
  state = !state;
  if (stepsPerRevolution==0){
    Serial.println("Pokreni steper?");
    if (Serial.read()=='Y'){
      stepsPerRevolution = 10;
      }
    else{
      stepsPerRevolution = 0;
      }
    }
  else if(stepsPerRevolution==10){
    Serial.println("Zaustavi steper?");
    if (Serial.read()=='Y'){
      stepsPerRevolution = 0;
      }
    else if(Serial.read()=='N'){
      stepsPerRevolution = 10;
      }
    }
}
