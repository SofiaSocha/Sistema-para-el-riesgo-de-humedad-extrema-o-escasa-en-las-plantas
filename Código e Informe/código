int sensor = A0;
int greenLed = 6;
int yellowLed = 8;
int redLed = 7;
int humidity = 0;

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  humidity = analogRead(sensor);
  Serial.print("Humidity: ");
  Serial.println(humidity);

  // Very humid
  if(humidity <= 400) {
    digitalWrite(redLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
  }
  // Medium humidity
  else if(humidity >= 400 && humidity <= 700) {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, LOW);
  }
  // Very dry
  else if(humidity >= 700) {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, HIGH);
  }

  delay(500);
}
