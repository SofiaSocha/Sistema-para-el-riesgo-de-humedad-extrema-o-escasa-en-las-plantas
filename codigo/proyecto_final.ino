int sensor = A0;

int ledVerde = 6;
int ledAmarillo = 8;
int ledRojo = 7;

int humedad = 0;

void setup() {

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  humedad = analogRead(sensor);

  Serial.print("Humedad: ");
  Serial.println(humedad);

  // Muy humedo
  if(humedad <= 400) {

    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledVerde, LOW);

  }

  // Humedad media
  else if(humedad >= 400  && humedad <= 700) {

    digitalWrite(ledRojo, LOW);
    digitalWrite(ledAmarillo, HIGH);
    digitalWrite(ledVerde, LOW);

  }


  // Muy seco
  else if(humedad >=700) {

    digitalWrite(ledRojo, LOW);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledVerde, HIGH);

  }

  delay(500);
}
