#include "StepMotor.h"

// Define stepper instance, with pin numbers (IN1, IN2, IN3, IN4)
StepMotor stepper(8,9,10,11);

int FULL_ROTATION_STEPS = 4095;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // StepMotor example usage

  // Rotate step in clockwise direction
  stepper.rotateClock(FULL_ROTATION_STEPS);
  delay(500);

  // Rotate step in counter-clockwise direction
  stepper.rotateCounter(FULL_ROTATION_STEPS);
  delay(500);
}
