/*
  ServoStepper.h - Library for controlling servo motors
  Created by Amit Bourmad, 2018-12-03
*/

#include "Arduino.h"
#include "ServoStepper.h"

/**
 * Describes the inputs values (low/high) at each step
 * Each column is a step (total 8)
 * Each row is an input value of 1/0 (total 4) 
 */
int stepMatrix[8][4] = {
  {0, 0, 0, 1},
  {0, 0, 1, 1},
  {0, 0, 1, 0},
  {0, 1, 1, 0},
  {0, 1, 0, 0},
  {1, 1, 0, 0},
  {1, 0, 0, 0},
  {1, 0, 0, 1}
};

ServoStepper::ServoStepper(int pin1, int pin2, int pin3, int pin4) {
  _pin1 = pin1;
  _pin2 = pin2;
  _pin3 = pin3;
  _pin4 = pin4;
  _currDirection = 1;
  _currStep = 0;
  pinMode(_pin1, OUTPUT);
  pinMode(_pin2, OUTPUT);
  pinMode(_pin3, OUTPUT);
  pinMode(_pin4, OUTPUT);
}

void ServoStepper::rotate(int dir, int steps) {
  for (int i = steps; i >= 0; i--) {
    // Send command to servo
    _makeStep(); 
    
    // Stepper write stepper(steps)
    _updateParameters(dir);
    
    // Must - without it the servo won't spin
    delay(2);
  }
}

void ServoStepper::rotateClock(int steps) {
  rotate(1, steps);
}

void ServoStepper::rotateCounter(int steps) {
  rotate(-1, steps);
}

void ServoStepper::_makeStep() {
  digitalWrite(_pin1, stepMatrix[_currStep][0]);
  digitalWrite(_pin2, stepMatrix[_currStep][1]);
  digitalWrite(_pin3, stepMatrix[_currStep][2]);
  digitalWrite(_pin4, stepMatrix[_currStep][3]);
}

void ServoStepper::_updateParameters(int dir) {
  _currStep += dir;
  
  if (_currStep > 7) {
    _currStep = 0;
  } else if (_currStep < 0) {
    _currStep = 7;
  }
}
