#include <Arduino.h>
#include "DRV8825.h"

// using a 400-step motor
#define MOTOR_STEPS 400

#define MICROSTEPS 8

// configure the pins connected
#define DIR 10
#define STEP 9
 
#define MODE0 13
#define MODE1 12
#define MODE2 11

#define RPM 120

//DRV8825 stepper(MOTOR_STEPS, DIR, STEP);
DRV8825 stepper(MOTOR_STEPS, DIR, STEP, MODE0, MODE1, MODE2);

void setup() {
    // Set target motor RPM
    stepper.begin(RPM, MICROSTEPS);
    stepper.enable();
}

void loop() {
    delay(1000);

    /*
     * Moving motor in full step mode is simple:
     */
    //stepper.setMicrostep(1);  // Set microstep mode to 1:1

    // One complete revolution is 360°
    //stepper.move(-1600);     // forward revolution    
    //delay(500);
    //stepper.move(1600);    // reverse revolution
    stepper.rotate(360);
    delay(500);
    stepper.rotate(-360);
}
