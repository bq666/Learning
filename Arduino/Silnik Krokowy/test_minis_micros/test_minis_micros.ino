#define PINSTEP 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(2000000);
//  Serial.println(millis());
  Serial.println(micros()); 
}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.println(millis());
  Serial.println(micros());
}
