#define PINSTEP 2

void setup() { // <----------------------------------------------------------------------- SETUP
//  noInterrupts();
//  interrupts();

  Serial.begin(9600);
  Serial.println("Serial begin initiate"); 

  pinMode(PINSTEP, OUTPUT);
  pinMode(3, INPUT_PULLUP);
}

int hzStart = 31;



int hzStop = 31;


// -------------------------------------------------- MOTION PARAMETERS
int startRadiusStart = 1;
int startRadiusStop = 1;
int stopRadiusStart = 1;
int stopRadiusStop = 1;




int hzAct = 0;
int hzLast = 0;
int hzAccel = 5;
int hzDelay = 10;

int hzSpeed = 500;


void loop() { // <------------------------------------------------------------------------ LOOP
//--------------------------------------------------- MOTION CALCULATIONS
  int numSteps = 0;
  int i = 0;
  
  int numStepsPowerAccel = 0; // <------------- POWER ACCELERATION STEPS
  while(hzAct - hzLast < hzAccel){ 
    hzAct = startRadiusStart * pow(2, i);
    i++;    
    numSteps++;
    makeStep(hzAct, PINSTEP);
  }
  numStepsRamp = numSteps;

  hzAct = 0; // <------------------------------ SLOWING DOWN TO SPEED
  numSteps = 0; 
  i = 0; 
  hzAct = hzAccel;
  int numStepsSlowingToSpeed = 0;
  while(hzAct <= hzAccel){
    hzAct = sqrt(hzAct);
    i++;
    
    makeStep(hzAct, PINSTEP);
  }
  
  
  while(hzAct <= hzSpeed



//--------------------------------------------------- MOTION
  hzAct = 0;
  int i = 0;
  while(hzAct - hzLast < hzAcceleration){
    hzAct = pow(2, i);
    i++;
    makeStep(hzAct, PINSTEP);
  }
  
  
}


void makeStep(int hzAct, byte PIN){
  Serial.println(hzAct);
//  if(hzAct < 31){
//    digitalWrite(PIN, HIGH);
//    delay((1000/hzAct)/2);
//    digitalWrite(PIN, LOW);
//    delay((1000/hzAct)/2);
//  }else{
//    digitalWrite(PIN, HIGH);
//    delayMicroseconds((1000000/hzAct)/2);
//    digitalWrite(PIN, LOW);
//    delayMicroseconds((1000000/hzAct)/2);
//  }
}

