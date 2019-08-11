#define PINSTEP 2

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105

void setup() { // <----------------------------------------------------------------------- SETUP

//  interrupts();
//  noInterrupts();
  Serial.begin(2000000);
  Serial.println("Serial begin initiate"); 

  pinMode(PINSTEP, OUTPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
}


// -------------------------------------------------- MOTION PARAMETERS
int hzSpeed = 1000;
int steps = 800;


//int startSteps = 80; //160; //80 ;

int startSteps = hzSpeed * 80.0/500.0;
//int stopSteps = 150; //300; //150 ;
int stopSteps = hzSpeed * (150.0/500.0);

//int hzMinStart = 15;
int hzMinStart = hzSpeed * (15.0/500.0); 
//int hzMinStop = 100;
int hzMinStop = hzSpeed * (100.0/500.0); 




float hzAct = 0;


// 1  1,75 A;   startSteps = 50;  stopSteps = 80;   hzMinStart = 100;   hzMinStop = 10;     hzSpeed = 500; 
// 2  1,75 A;   startSteps = 50;  stopSteps = 70;   hzMinStart = 10;    hzMinStop = 10;     hzSpeed = 500; 
// 3  1,75 A;   startSteps = 70;  stopSteps = 80;   hzMinStart = 5;     hzMinStop = 5;      hzSpeed = 500; 
// 4  1,75 A;   startSteps = 80;  stopSteps = 150;  hzMinStart = 15;    hzMinStop = 100;    hzSpeed = 500;    <--- Pati best
// Pati mówi że od minimum  30 Hz            a maks 1kHz 

// todo 
// na micros() 
// przy micros pamiętaj ze po 70 minutach licznik się obruci !!!
// sterownik wyjście błąd 


void loop() { // <------------------------------------------------------------------------ LOOP
//  Serial.print(float(80.0/500.0), 6); 
//  Serial.print(startSteps); 
//  while(1); 
//--------------------------------------------------- MOTION
  if(digitalRead(3) == LOW){
    digitalWrite(4, HIGH);
    hzAct = 0;
    float oneStepAccel = PI / float(startSteps);
    int i = 0;
    int ii = 0;
    while(hzAct < hzSpeed){ // <--------------------- START
      i++;
//      digitalWrite(4, HIGH);
      hzAct = hzMinStart + ((hzSpeed - hzMinStart) * 0.5 +((hzSpeed - hzMinStart) * 0.5 * sin(-HALF_PI + (i * oneStepAccel))));
//      digitalWrite(4, LOW); 
//      Serial.print("i: ");
//      Serial.print(i);
//      Serial.print( "  hzAct:");
//      Serial.println(hzAct);
      makeStep(hzAct, PINSTEP);
    }
    
    i = 0;
    while(i < steps - startSteps - stopSteps){ // <----------------------------- MOVE
      i++;
//      Serial.print("ii: ");
//      Serial.print(i);
      makeStep(hzAct, PINSTEP);
    }

    i = 0;
    float oneStepDelay = PI / float(stopSteps);
    while(hzAct > hzMinStop){ // <----------------------- STOP
      i++;
      hzAct = hzMinStop + ((hzSpeed - hzMinStop) * 0.5 +((hzSpeed - hzMinStop) * 0.5 * sin(HALF_PI + (i * oneStepDelay))));
//      Serial.print("iii: ");
//      Serial.print(i);
      makeStep(hzAct, PINSTEP);
    }
  }
  digitalWrite(4, LOW);
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

