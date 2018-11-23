#include <TimerOne.h>
#include <Arduino.h>
#include "DRV8825.h"


#define FSR_PIN01 0   // Analog input A0
#define FSR_PIN02 1   // Analog input A1

// using a 400-step motor
#define MOTOR_STEPS 400

// microstepping is not supported by this motor
#define MICROSTEPS 2

#define MOTOR_ACCEL 100
#define MOTOR_DECEL 200

// configure the pins connected
#define DIR 13
#define STEP 12
 
#define MODE0 9
#define MODE1 10
#define MODE2 11

#define RPM 10

float diff;

//DRV8825 stepper(MOTOR_STEPS, DIR, STEP);
DRV8825 stepper(MOTOR_STEPS, DIR, STEP, MODE0, MODE1, MODE2);

// Compute the differential between the two sensors
void fsr_callback(void) {
  diff = float(analogRead(FSR_PIN01)) / 1024.0 - float(analogRead(FSR_PIN02)) / 1024.0;
}
 
void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(115200);

  // Set up timer for fsr sensors
  Timer1.initialize(500);
  Timer1.attachInterrupt(fsr_callback);

  // Set up motor
  stepper.begin(RPM, MICROSTEPS);
  stepper.enable();
}
 
void loop(void) {
  
  Serial.println(diff);     // the raw analog reading

  stepper.rotate(diff * 10);
  
} 
