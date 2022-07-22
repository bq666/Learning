#define STEP 2

void setup() {
  // put your setup code here, to run once:
  //  cli();
  Serial.begin(9600);
  pinMode(STEP, OUTPUT);
}

int hzStart = 0;
int startRadiusStart = 50;
int hzAcceleration = 5;
int startRadiusStop = 50;
int hzSpeed = 500;
int stopRadiusStart = 50;
int hzDelay = 10;
int stopRadiusStop = 50;
int hzStop = 0;
int numSteps = 200;
int hzAct = 0;


void loop() { // <------------------------ LOOP --------------------
  // <-------------------------------------- Start acceleration part
  int stopGoodStepStart = 0;
  int fGoodStepStart = 0;

  for(int i = 0; i <= startRadiusStart; i++){
    int delta = int(-sqrt(pow(startRadiusStart, 2) - pow(i+1, 2)) + startRadiusStart) - int(-sqrt(pow(startRadiusStart, 2) - pow(i, 2)) + startRadiusStart);
    if(delta != 0 && fGoodStepStart == 0){
      fGoodStepStart = i + 1;  
    }
    if(delta > hzAcceleration){
      stopGoodStepStart = i;      
      break;
    }    
  }

  // Start slowly to speed part


  // Start slowly to delay part


  // Start slowly stop part


  // Start number of steps to stop



  // Start motion <---------------------------- Motion 
  for(int i = 0; i <= numSteps; i++){
    hzAct += int(-sqrt(pow(startRadiusStart, 2) - pow(fGoodStepStart + i, 2)) + startRadiusStart);
    Serial.println(hzAct);
  }
  
//  for(int i = 0; i <= num_steps; i++){
    
    
    
//    digitalWrite(STEP, HIGH);
//    delayMicroseconds((1000000/hzAct)/2);
//    digitalWrite(STEP, LOW);
//    delayMicroseconds((1000000/hzAct)/2);    

  
  
  
  
//  int test = 0;
//  for(int i = 0; i <= 10000; i++){
//    digitalWrite(STEP,HIGH);
//    digitalWrite(STEP,LOW);
//    test = sqrt(2 * i + startRadiusStart - pow(i, 2));
//  }
  while(1);
}
