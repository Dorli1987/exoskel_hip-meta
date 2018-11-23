#include <Arduino.h>
#include "DRV8825.h"

#define FSR_PIN 0

// using a 400-step motor
#define MOTOR_STEPS 400

// microstepping is not supported by this motor
#define MICROSTEPS 1

#define MOTOR_ACCEL 100
#define MOTOR_DECEL 200

// configure the pins connected
#define DIR 11
#define STEP 12
 
#define MODE0 8
#define MODE1 9
#define MODE2 10

#define RPM 10

//DRV8825 stepper(MOTOR_STEPS, DIR, STEP);
DRV8825 stepper(MOTOR_STEPS, DIR, STEP, MODE0, MODE1, MODE2);

double value = 0;

void setup() {
    Serial.begin(9600);
    
    stepper.begin(RPM);
    stepper.enable();
}

void loop() {
    value = analogRead(FSR_PIN) / 1024.0;

    Serial.println(value);

    stepper.move(value * 10);
}
