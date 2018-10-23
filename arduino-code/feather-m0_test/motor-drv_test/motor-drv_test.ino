int steps=9;
int dir =10;
int stepTime=10;

int numsteps;
bool reverse;


void setup() {
  
  pinMode(steps, OUTPUT);
  pinMode(dir, OUTPUT);

  numsteps = 0;
  reverse = false;
}


void loop() {
  if (numsteps > 400) {
    numsteps = 0;
    reverse = !reverse;
  }

  digitalWrite(dir, reverse ? LOW : HIGH);

  digitalWrite(steps, HIGH);   
  delay(stepTime);                      
  digitalWrite(steps, LOW);    
  delay(stepTime);
  numsteps++;
  
}
