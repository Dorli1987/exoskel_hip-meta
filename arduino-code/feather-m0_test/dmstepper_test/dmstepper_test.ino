#include <dmstepper.h>

int steps=9;
int dir =10;

DMStepper motor(dir, steps);

void setup() {
  motor.acceleration = 15000;
}

void loop() {
  motor.run(1, 100, 200);
  delay(1000);

  motor.run(-1, 100, 200);
  delay(1000);
  
}
