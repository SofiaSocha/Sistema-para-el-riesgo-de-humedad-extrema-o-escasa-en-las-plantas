# Sistema-para-el-riesgo-de-humedad-extrema-o-escasa-en-las-plantas
Sistema embebido con Arduino UNO para monitoreo de humedad en plantas usando sensor resistivo y LEDs indicadores.

## Descripción

Proyecto de Circuitos Digitales realizado en la Universidad de San Buenaventura, para realizar un sistema embebido con Arduino UNO para monitorear la humedad en plantas domésticas mediante un sensor de humedad y LEDs indicadores.

## Problemática

La problemática aborda el riego inadecuado en hogares y huertos urbanos, causada por la falta de tiempo o conocimiento que provoca la muerte de las plantas por estrés hídrico o exceso de agua, además de un desperdicio del recurso. Este proyecto busca automatizar el monitoreo de humedad para facilitar el cuidado de las plantas y promover el uso eficiente del agua.

## Integrantes

- Sofía Socha
- Valentina Cruz
- Mariana Javier
- Alejandra Triana

## Componentes utilizados

- Arduino UNO
- Sensor de humedad resistivo
- LEDs indicadores
- Resistencias de 220Ω
- Protoboard
- Cables jumper
  
## Instrucciones de uso

Para ejecutar el proyecto es necesario conectar el sensor de humedad al pin analógico A0 del Arduino UNO y los LEDs indicadores a los pines digitales 6, 7 y 8 mediante resistencias de 220 Ω. Posteriormente, se debe cargar el archivo del código desde Arduino IDE utilizando un cable USB conectado al computador. Una vez cargado el programa, el sistema comenzará a leer continuamente los valores de humedad detectados por el sensor y activará automáticamente el LED correspondiente según el nivel registrado. 

## Funcionamiento

1. Ubicar el sensor en la maceta de la planta.
2. El sensor detecta la temperatura del agua y nivel de humedad.
3. Arduino UNO recibe la señal analógica mediante el pin A0.
4. El sistema procesa los valores obtenidos y clasifica el nivel de humedad en tres estados y dependiendo de eso los LEDs tienen los siguientes comportamientos:
   - LED rojo -> Humedad a temperatura caliente
   - LED amarillo -> Humedad a temperatura media
   - LED verde -> No hay humedad

## Lógica del sistema

El programa fue desarrollado en lenguaje C++ utilizando Arduino IDE, el sistema realiza lecturas continuas mediante la función `analogRead()`, la cual obtiene valores entre 0 y 1023 correspondientes al nivel de humedad detectado por el sensor.

Posteriormente, el Arduino compara estos valores utilizando estructuras condicionales `if`, `else if` y `else` para determinar qué LED debe encenderse.

### Clasificación implementada

| Condición | Rango ADC | LED |
|---|---|---|
| Muy húmedo a temperatura caliente| ≤ 400 | Rojo |
| Humedad media a temperatura media | 400 – 700 | Amarillo |
| Seco | ≥ 700 | Verde |

## Fragmento representativo del código

```cpp
if(humidity <= 400) {
  digitalWrite(redLed, HIGH);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
}

else if(humidity >= 400 && humidity <= 700) {
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, HIGH);
  digitalWrite(greenLed, LOW);
}

else {
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, HIGH);
}
```

Este fragmento representa la lógica principal del sistema ya que dependiendo del valor leído por el sensor, Arduino activa únicamente el LED correspondiente al estado de humedad detectado.

---

## Código fuente completo

El archivo completo del programa puede encontrarse en:

[Código del proyecto](Código/código_proyecto.ino)
