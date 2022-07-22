//#include <avr/wdt.h>
#define STEP 2

void setup() {
  // put your setup code here, to run once:
  //  wdt_disable();

  Serial.begin(9600);

  pinMode(STEP, OUTPUT);
}

int hzStart = 0;
const int startRadiusStart = 50;
int hzAcceleration = 5;
const int startRadiusStop = 50;
int hzSpeed = 100;
const int stopRadiusStart = 50;
int hzDelay = 10;
const int stopRadiusStop = 50;
int hzStop = 0;
const int num_steps = 1000;



int i = 0;
int srs1[startRadiusStart];
int srs2[startRadiusStop];
int srs3[stopRadiusStart];
int srs4[stopRadiusStop];
int motion[num_steps];


void loop() {
  // put your main code here, to run repeatedly:
  // wdt_reset();
  //  cli(); // disable interups

  motion[0] = hzStart;
  for(int i = 1; i <= num_steps; i++){
    if(srs1[i+1] - srs1[i] < hzAcceleration){
      motion[i] = srs1[i+1] - srs1[i];
    }    
  }







//  staRsta_int(&srs1[0], startRadiusStart);
//  for (int i = 0; i < (sizeof(srs1) / sizeof(int)); i++) {
//    Serial.println(srs1[i]);
//  }
//
//  staRsto_int(&srs2[0], startRadiusStop);
//  for (int i = 0; i <sizeof(srs2) / sizeof(int); i++){
//    Serial.println(srs2[i]);
//  }
//
//  stoRsta_int(&srs3[0], stopRadiusStart);
//  for (int i = 0; i < (sizeof(srs3) / sizeof(int)); i++) {
//    Serial.println(srs3[i]);
//  }
//
//  stoRsto_int(&srs4[0], stopRadiusStop);
//  for (int i = 0; i <sizeof(srs4) / sizeof(int); i++){
//    Serial.println(srs4[i]);
//  }
 
  

  //  timeSpeed = (1000000/hzSpeed)/2;
  //  timeStep = (1000000/hzStep)/2;
  //  for(i=0; i<1000; i+=hzStep){
  //    digitalWrite(STEP, HIGH);
  //    delayMicroseconds(timeSpeed - i);
  //    digitalWrite(STEP, LOW);
  //    delayMicroseconds(timeSpeed - i);
  //  };
  while(1);
}


void staRsta_int(int *srs, int radius) {
  int i;
  for (i = 0; i <= radius; i++) {
    srs[i] = -sqrt(pow(radius, 2) - pow(i+1, 2)) + radius;
    //    srs[i] = int(-sqrt(pow(radius) - pow(i)) + radius);
  }
}

void staRsto_int(int *srs, int radius) {
  int i;
  for (i = 0; i <= radius; i++) {
    srs[i] = sqrt(2 * i * radius - pow(i, 2));
    //    srs[i] = int(-sqrt(pow(radius) - pow(i)) + radius);
  }
}

void stoRsta_int(int *srs, int radius) {
  int i;
  for (i = 0; i <= radius; i++) {
    srs[i] = sqrt(pow(radius, 2) - pow(i+1, 2));
    //    srs[i] = int(-sqrt(pow(radius) - pow(i)) + radius);
  }
}

void stoRsto_int(int *srs, int radius) {
  int i;
  for (i = 0; i <= radius; i++) {
    srs[i] = -sqrt(2 * i * radius - pow(i, 2)) + radius;
    //    srs[i] = int(-sqrt(pow(radius) - pow(i)) + radius);
  }
}
