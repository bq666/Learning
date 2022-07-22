#define PINSTEP 2

void setup() {
  noInterrupts(); 
  Serial.begin(2000000);
  Serial.println("Serial begin initiate");

  pinMode(PINSTEP, OUTPUT);
  pinMode(3, INPUT_PULLUP);
}

int hzStart = 31;
int startRadiusStart = 50;
int hzAcceleration = 5;
int startRadiusStop = 50;
int hzSpeed = 500;
int stopRadiusStart = 50;
int hzDelay = 10;
int stopRadiusStop = 50;
int hzStop = 31;
int numSteps = 0;
int hzAct = 0;


void loop() {
  if(digitalRead(3) == LOW){
    int start = hzSpeed / 3;
    int acceleration = (hzSpeed / 3) * 2; 
    int i_acceleration = 0;
    hzAct = hzStart; 
    for(int i = 1; hzAct < start; i++){ // <-------- start
      hzAct += i;
      makeStep(hzAct, PINSTEP);
      i_acceleration = i;
    } 
    for(int i = 0; hzAct < acceleration; i++){ // <-------- acceleration
      makeStep(hzAct, PINSTEP);
      hzAct += i_acceleration;
    }    
    for(int i = i_acceleration; i > 0; i--){ // <-------- slowly
      makeStep(hzAct, PINSTEP);
      hzAct += i;
    }
    for(int i = 0; hzAct < hzSpeed; i++){ // <-------- step to speed
      hzAct++; 
      makeStep(hzAct, PINSTEP);
    }    
    for(int i = 0; i <= 693; i++){ // <-------- steps 
      makeStep(hzAct, PINSTEP);
    }
    int stepsToStop = numSteps;
    for(int i = 0; hzAct >= acceleration; i--){ // <-------- slowly
      makeStep(hzAct, PINSTEP);
      hzAct += i;
    }
    for(int i = 0; hzAct > start; i++){ // <---------- delay
      makeStep(hzAct, PINSTEP);
      hzAct -= i_acceleration;
    }
//    Serial.print("i_acceleration:");
//    Serial.print(i_acceleration);
    for(int i = i_acceleration; hzAct > 31; i--){
      hzAct -= i;
      makeStep(hzAct, PINSTEP);   
    }
//  Serial.println(numSteps);
//  numSteps = 0;  
  }
//  digitalWrite(PINSTEP, HIGH);
//  delayMicroseconds(16300);
//  digitalWrite(PINSTEP, LOW);
//  delayMicroseconds(16383);

  


hzAct = 0;
}


void makeStep(int hzAct, byte PIN){
//  if(hzAct == 0){  // <------------------------- PAMIĘTAJ ŻE NIE DZIELI SIĘ PRZEZ 0 !!!!!!!!!!!!!!!!!!!!
//    hzAct += 1;
//  }
  
//  Serial.print( " hzAct:");
  Serial.println(hzAct);
  if(hzAct < 31){
    digitalWrite(PIN, HIGH);
    delay((1000/hzAct)/2);  // NIE DZIAŁA Z WYŁĄCZONYMI PRZERWANIAMI !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    digitalWrite(PIN, LOW);
    delay((1000/hzAct)/2);
//    Serial.print( " hzAct:");
//    Serial.print(hzAct);
//    Serial.print(" "); 
//    Serial.println((1000/hzAct)/2);
  }else{
//    Serial.print( " hzAct:");
//    Serial.print(hzAct);
//    Serial.print(" "); 
//    Serial.println((1000000/hzAct)/2);
    digitalWrite(PIN, HIGH);
    delayMicroseconds((1000000/hzAct)/2);
    digitalWrite(PIN, LOW);
    delayMicroseconds((1000000/hzAct)/2);
  }
}

