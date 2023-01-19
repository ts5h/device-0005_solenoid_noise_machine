/*
  Device-0005 / Solenoid Noise Machine
  ATtimy85
  
  ts5h / 0bjekt
 */

const int unsigned LED = 3;
const int unsigned SOLENOID = 4;

const int unsigned DUR = 15;

int unsigned num;
int unsigned randomDelay;

void setup() {
  randomSeed(analogRead(1));
  
  pinMode(LED, OUTPUT);
  pinMode(SOLENOID, OUTPUT);

  digitalWrite(LED, HIGH);
  digitalWrite(SOLENOID, LOW);
  delay(2000);
}

void loop() {
  num = random(10);
  if (num == 0) {
    // ~5s interval
    randomDelay = random(7971);
  } else if (num <= 2) {
    // ~1s interval
    randomDelay = random(1971);
  } else {
    // ~250ms interval
    randomDelay = random(221);
  }
  randomDelay += DUR;
  
  digitalWrite(SOLENOID, HIGH);
  delay(DUR);
  digitalWrite(SOLENOID, LOW);
  delay(randomDelay);
}
