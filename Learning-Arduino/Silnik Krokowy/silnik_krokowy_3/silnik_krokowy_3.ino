#define STEP_PIN 2

void setup() {
  // put your setup code here, to run once:
  cli();
  Serial.begin(9600);
  Serial.println("Serial begin initiate");
  pinMode(STEP_PIN, OUTPUT);
}

int hzStart = 0;
int startRadiusStart = 200;  // min: 1  max: 253<--- przerób na byte !!!
int hzAcceleration = 100;  // min: 1 max:<--- przerób na byte !!!    
int startRadiusStop = 200; // min:
int hzSpeed = 500;
int stopRadiusStart = 50;
int hzDelay = 10;
int stopRadiusStop = 50;
int hzStop = 0;
int numSteps = 200;
int hzAct = 0;

byte circleDelta_1[255];
byte circleDelta_2[255];
int motionArray[255];

void loop() {  // <------------------------------------------------------------------------------------------------------ START LOOP
  // put your main code here, to run repeatedly:
  
  setCircleDelta_1(&circleDelta_1[0], startRadiusStart);
  setCircleDelta_2(&circleDelta_2[0], startRadiusStop);

  startMotion(hzSpeed, true, hzAcceleration, hzStart, &circleDelta_1[0], &circleDelta_2[0], &motionArray[0], STEP_PIN);

  for(int i = 0; motionArray[i] > 0; i++){
//    Serial.println(motionArray[i]); 
    Serial.println((1000000/motionArray[i])/2); 
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds((1000000/motionArray[i])/2);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds((1000000/motionArray[i])/2);
  }

  for(int i = 0; i < 200; i++){
    makeStep(hzSpeed, STEP_PIN);
  }
  delay(1000);
//  startMotion(hzSpeed, true, hzAcceleration, hzStart, &circleDelta_1[0], &circleDelta_2[0], &motionArray[0], STEP_PIN);
//  for(int i = 0; i < 50; i++){
//    makeStep(hzSpeed, STEP_PIN);
//  }
  
//  for(int i = 0; i < startRadiusStop; i++){
//    Serial.print(i);
//    Serial.print(" ");
//    Serial.println(circleDelta_2[i]);
//  }

  
//  Serial.println("Stop"); 
  while(1);
}  // <------------------------------------------------------------------------------------------------------------------- STOP LOOP

int startMotion(int hzSpeed, bool motion, int hzAcceleration, int hzStart, byte *circleDelta_1, byte *circleDelta_2, int *motionArray, byte PIN){
  int hzSpeedAct = hzStart;
  int steps = 0;  
  byte firstStepSlow = 0;
  byte deltaSlow = 0;

  byte i = 0;
  while(firstStepSlow == 0){
//    Serial.print("i:");
//    Serial.print(i);
//    Serial.print("  circleDelta_2[i]:");
//    Serial.print(circleDelta_2[i]);
//    Serial.print("  hzAcceleration:");
//    Serial.print(hzAcceleration);
    if(circleDelta_2[i] < hzAcceleration){
      firstStepSlow = i;
    }
//    Serial.print(" firstStepSlow:");
//    Serial.println(firstStepSlow);
    i++;
  }


  i = firstStepSlow;
  while(1){  
    if(circleDelta_2[i] > 0){
      deltaSlow += circleDelta_2[i];
    } else {
      break; 
    }
//    Serial.print("i:");
//    Serial.print(i);
//    Serial.print("  circleDelta_2[i]:");
//    Serial.print(circleDelta_2[i]);
//    Serial.print("  hzSpeed:");
//    Serial.print(hzSpeed);  
//    Serial.print(" deltaSlow:");
//    Serial.println(deltaSlow);
  i++;
  }


//------------------------------------------------------------------ MOTION
  byte s = 0;
  byte ss = 0;
  byte sss = 0;
//  Serial.print("firstStepSlow:");
//  Serial.print(firstStepSlow);
//  Serial.print(" deltaSlow:");
//  Serial.println(deltaSlow);
  
  while(hzSpeedAct < hzSpeed){
//    Serial.print("hzSpeedAct:");
//    Serial.print(hzSpeedAct);
//    Serial.print(" hzSpeed:");
//    Serial.println(hzSpeed);
    if((circleDelta_1[s] < hzAcceleration) && circleDelta_1[s] != 255){
      hzSpeedAct += circleDelta_1[s];
      s++;
    }else if((hzSpeedAct + deltaSlow) < hzSpeed){
      hzSpeedAct += hzAcceleration;
    }else if(hzSpeedAct < hzSpeed){
      hzSpeedAct += circleDelta_2[firstStepSlow + ss];
      ss++;
    }else{
      break;
    }
       
    if(motion == true){
//      Serial.println(hzSpeedAct);
      motionArray[sss] = hzSpeedAct;
      sss++;
//      makeStep(hzSpeedAct, STEP_PIN); // <------------------------------- TUTAJ DZIAŁAM !!!!!!!!!!!!!!!!!!!!!!1
    }else{
      steps ++;
    }
  }
}


void setCircleDelta_1(byte *circleDelta_1, int startRadiusStart){
  int j = 0;
  for(byte i = 1; i <= startRadiusStart + 1; i++){
//    Serial.print(i);
//    Serial.print(" "); 
//    Serial.println(byte(-sqrt(pow(startRadiusStart, 2) - pow(i, 2)) + startRadiusStart));
    if(byte(-sqrt(pow(startRadiusStart, 2) - pow(i, 2)) + startRadiusStart) > 0){     
      circleDelta_1[j] = (byte(-sqrt(pow(startRadiusStart, 2) - pow(i, 2)) + startRadiusStart) - (byte(-sqrt(pow(startRadiusStart, 2) - pow(i - 1, 2)) + startRadiusStart))); 
      j++;
    }         
  }
  circleDelta_1[j] = 255;
//  Serial.println("Stop set");
//  for(int i = 0; i < 100; i++){  
//    Serial.println(circleDelta_1[i]);
//  }
}


void setCircleDelta_2(byte *circleDelta_2, int startRadiusStop){
  int j = 0;
  for(byte i = 1; i <= startRadiusStop + 1; i++){
//    Serial.print(i);
//    Serial.print(" "); 
//    Serial.println(byte(sqrt(2 * i * startRadiusStop - pow(i, 2))));
    if(byte(sqrt(2 * i * startRadiusStop - pow(i, 2))) < startRadiusStop){     
      circleDelta_2[j] = (byte(sqrt(2 * i * startRadiusStop - pow(i, 2)) - byte(sqrt(2 * (i - 1) * startRadiusStop - pow(i - 1, 2))))); 
      j++;
    }       
  }
//  Serial.println("Stop set");
}

void makeStep(int hzSpeed, byte pin){
//  Serial.print(" hzSpeedAct:");
//  Serial.println(hzSpeed);
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds((1000000/hzSpeed)/2);
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds((1000000/hzSpeed)/2);
//  Serial.print("(1000000/hzSpeed)/2): ");
//  Serial.println((1000000/hzSpeed)/2); 
}

