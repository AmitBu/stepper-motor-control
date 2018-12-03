/*
  ServoStepper.h - Library for controlling servo motors
  Created by Amit Bourmad, 2018-12-03
*/
#ifndef ServoStepper_h
#define ServoStepper_h

#include "Arduino.h"


class ServoStepper
{
  public:
    ServoStepper(int pin1, int pin2, int pin3, int pin4);
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
