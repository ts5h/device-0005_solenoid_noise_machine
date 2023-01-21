/*
  Device-0005 / Solenoid Noise Machine
  ATtimy85
  
  ts5h / 0bjekt
 */

const int unsigned SOLENOID = 3;
const int unsigned LED = 4;

const int unsigned DUR = 10;

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
  num = random(25);
  if (num == 0) {
    randomDelay = random(8001 - DUR * 2);
  } else if (num == 1) {
    randomDelay = random(4001 - DUR * 2);
  } else if (num <= 5) {
    randomDelay = random(1001 - DUR * 2);
  } else {
    randomDelay = random(251 - DUR * 2);
  }
  randomDelay += DUR;
  
  digitalWrite(SOLENOID, HIGH);
  delay(DUR);
  digitalWrite(SOLENOID, LOW);
  delay(randomDelay);
}
