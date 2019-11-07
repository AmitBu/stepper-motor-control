# Stepper motor control

C++ class library that controls a stepper motor,
Created it for stepper motor 28BYJ-48, after other code examples didn't work well.

## How to use
You can look at the [Arduino example file](examples/stepper-control-example/stepper-control-example.ino).

![Running the sample code](stepper-sample.gif)
_(Running the example code)_

Steps:
1. Clone repository, or download `StepMotor.h` and `StepMotor.cpp` (put them in your arduino project folder)
2. Include library inside arduino (.ino) file
```C++
#include "StepMotor.h"
```
3. Create `StepMotor` instance 
```C++
StepMotor stepper(8,9,10,11);
```
4. Use instance to control stepper, examples:
```C++
// Rotate clockwise 1000 steps
stepper.rotateClock(1000);

// Rotate counter-clockwise 1000 steps:
stepper.rotateCounter(1000);

// Rotate in the direction you choose (`1` - clockwise, `-1` - counter-clockwise)
stepper.rotate(-1, 1000);
```
