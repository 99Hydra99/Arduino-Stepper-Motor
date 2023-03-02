#include <Stepper.h>

volatile int stepsPerRevolution = 0;
Stepper myStepper = Stepper(2038, 8, 10, 9, 11);
int brzina=5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value=analogRead(A0);
  if(value>=0 && value<=255){
    myStepper.setSpeed(brzina*2);
    myStepper.step(10);
    }
  else if(value>=255 && value<=512){
    myStepper.setSpeed(brzina);
    myStepper.step(10);
    }
  else if(value>=513 && value<=767){
    myStepper.setSpeed(brzina);
    myStepper.step(-10);
    }
  else{
    myStepper.setSpeed(brzina*2);
    myStepper.step(-10);
    }
}
