#define led1 2
#define czas 1000


void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  digitalWrite(led1,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led1,HIGH);
  delay(czas);
  digitalWrite(led1,LOW);
  delay(czas);
}
