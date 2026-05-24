// Declaración de variables
int sensor = A0;
int greenLed = 6;
int yellowLed = 8;
int redLed = 7;
int humidity = 0;

void setup() {
  pinMode(greenLed, OUTPUT); // pinMode se utiliza para convertir LEDs en salida digital
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  Serial.begin(9600); // Indica que inicia la comunicación serial
}

void loop() {
  humidity = analogRead(sensor); // Lee el valor enviado para el sensor de humedad
  Serial.print("Humidity: "); // 
  Serial.println(humidity); // Escriba en la consola el valor de la variable humedad

//Function according to sensor values

  // Cuando se utiliza agua caliente y el sensor registra un valor menor o igual a 400, el LED rojo se enciende y los 
demás se apagan
  if(humidity <= 400) {
    digitalWrite(redLed, HIGH); // digitalWrite es lo que controla el estado de los LED (HIGH significa LED encendido y LOW LED apagado)
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
  }

  // Cuando se utiliza agua caliente y el sensor registra un valor 400 y 700, el LED amarillo se enciende y los demás se apagan.
  else if(humidity >= 400 && humidity <= 700) {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, LOW);
  }
  // Cuando el sensor está seco y registra un valor mayor o igual a 700, el LED verde se enciende y los demás se apagan
  else if(humidity >= 700) {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, HIGH);
  }

  delay(500); // El programa espera 500 milisegundos antes de repetir el proceso
}
