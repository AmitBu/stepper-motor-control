/*
  StepMotor.h - Library for controlling step motors
  Created by Amit Bourmad, 2018-12-03
*/
#ifndef StepMotor_h
#define StepMotor_h

#include "Arduino.h"


class StepMotor
{
  public:
    StepMotor(int pin1, int pin2, int pin3, int pin4);
    void rotate(int dir, int steps);
    void rotateClock(int steps);
    void rotateCounter(int steps);
  private:
    int _pin1;
    int _pin2;
    int _pin3;
    int _pin4;
    int _currDirection;
    int _currStep;
    void _makeStep();
    void _updateParameters(int dir);
};

#endif
