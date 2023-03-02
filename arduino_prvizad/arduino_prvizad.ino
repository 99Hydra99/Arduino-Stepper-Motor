#include <Stepper.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038; // 2038 -> link

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);
int brzina=10;
void setup() {
  // Nothing to do (Stepper Library sets pins as outputs)
  Serial.begin(9600);
}

void loop() {
  // Rotate CW slowly at 5 RPM
  if (Serial.available()){
  char promjena=Serial.read();
  
  if(promjena=='+'){
    brzina+=5;
    }
  else if(promjena=='-'){
    brzina-=5;
    }
  }
  myStepper.setSpeed(brzina);
  myStepper.step(stepsPerRevolution);
}
