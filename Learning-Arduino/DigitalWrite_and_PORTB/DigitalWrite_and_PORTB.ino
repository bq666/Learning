//#define PIN 9
#define PIN 1 //DDRB
void setup() {
  // put your setup code here, to run once:
//  pinMode(PIN, OUTPUT);
//  DDRB =  B00000010;
  DDRB |= (1<<PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(PIN, HIGH);
//  digitalWrite(PIN, LOW);
  PORTB = B00000000;
//  delay(1000);
  PORTB = B00000010;
//  delay(1000);
}
