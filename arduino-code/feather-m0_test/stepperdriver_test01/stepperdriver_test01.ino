#include <Arduino.h>
#include "DRV8825.h"

// using a 400-step motor
#define MOTOR_STEPS 400

// microstepping is not supported by this motor
#define MICROSTEPS 8

#define MOTOR_ACCEL 100
#define MOTOR_DECEL 200

// configure the pins connected
#define DIR 10
#define STEP 9
 
#define MODE0 13
#define MODE1 12
#define MODE2 11

#define STOPPER_PIN 6

#define RPM 20

//DRV8825 stepper(MOTOR_STEPS, DIR, STEP);
DRV8825 stepper(MOTOR_STEPS, DIR, STEP, MODE0, MODE1, MODE2);

void setup() {
    // Configure stopper pin to read HIGH unless grounded
    pinMode(STOPPER_PIN, INPUT_PULLUP);

    stepper.begin(RPM, MICROSTEPS);
    stepper.enable();

    stepper.startMove(100 * MOTOR_STEPS * MICROSTEPS); 
}

void loop() {
    // first, check if stopper was hit
    if (digitalRead(STOPPER_PIN) == LOW){

        int rpm = stepper.getRPM();

        stepper.setRPM(rpm + 10);
        //stepper.stop();
        
        // stepper.startBrake();
    }

    // motor control loop - send pulse and return how long to wait until next pulse
    unsigned wait_time_micros = stepper.nextAction();

    // 0 wait time indicates the motor has stopped
    if (wait_time_micros <= 0) {
        stepper.disable();       // comment out to keep motor powered
        delay(3600000);
    }

    // (optional) execute other code if we have enough time
    if (wait_time_micros > 100){
        // other code here
    }
}
