# Stepper motor control

C++ class library that controls a stepper motor,
Created it for stepper motor 28BYJ-48, after other code examples didn't work well.

## How to use
You can look at the [Arduino example file](servo-control-example.ino).

Steps:
1. Clone repository, or download `ServoStepper.h` and `ServoStepper.cpp` (put them in your arduino project folder)
2. Include library inside arduino (.ino) file
```C++
#include "ServoStepper.h"
```
3. Create `ServoStepper` instance 
```C++
ServoStepper stepper(8,9,10,11);
```
4. Use instance to control servo, examples:
```C++
// Rotate clockwise 1000 steps
stepper.rotateClock(1000);

// Rotate counter-clockwise 1000 steps:
stepper.rotateCounter(1000);

// Rotate in the direction you choose (`1` - clockwise, `-1` - counter-clockwise)
stepper.rotate(-1, 1000);
```