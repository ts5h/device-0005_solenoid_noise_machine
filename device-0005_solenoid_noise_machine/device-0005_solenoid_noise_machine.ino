/*
  Device-0005 / Solenoid Noise Machine
  ATtimy85
  
  ts5h / 0bjekt
 */

const int unsigned SOLENOID = 3;
const int unsigned LED = 4;

const int unsigned DUR = 20;
const int unsigned OPERATING_TIME = DUR * 2;

int unsigned num;
int unsigned randomDelay;

void setup() {
  randomSeed(analogRead(1));
  
  pinMode(SOLENOID, OUTPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(SOLENOID, LOW);
  digitalWrite(LED, HIGH);
  delay(1000);
}

void loop() {
  num = random(100);
  if (num == 0) {
    randomDelay = random(8001 - OPERATING_TIME);
  } else if (num <= 2) {
    randomDelay = random(2001 - OPERATING_TIME);
  } else if (num <= 7) {
    randomDelay = random(501 - OPERATING_TIME);
  } else if (num <= 17) {
    randomDelay = random(151 - OPERATING_TIME);
  } else {
    randomDelay = random(51 - OPERATING_TIME);
  }
  randomDelay += DUR;
  
  digitalWrite(SOLENOID, HIGH);
  delay(DUR);
  digitalWrite(SOLENOID, LOW);
  delay(randomDelay);
}
