int LedAzul = 17;

void setup(){
  Serial.begin(9600);
  pinMode(LedAzul, OUTPUT);
}

void loop(){
  digitalWrite(LedAzul, HIGH);
  delay(500);
  digitalWrite(LedAzul, LOW);
  delay(500);
}