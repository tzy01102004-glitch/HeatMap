#define NUM_THERMISTORS 4

int thermPins[NUM_THERMISTORS] = {A0, A1, A2, A3};

#define SERIES_RESISTOR 10000
#define THERMISTOR_NOMINAL 10000
#define TEMPERATURE_NOMINAL 25
#define B_COEFFICIENT 3988

float temperatures[NUM_THERMISTORS];

void setup() {
  Serial.begin(9600);
}

void loop() {

  for (int i = 0; i < NUM_THERMISTORS; i++) {

    int adcValue = analogRead(thermPins[i]);

    float resistance = SERIES_RESISTOR * ((1023.0 / adcValue) - 1.0);

    float steinhart;

    steinhart = resistance / THERMISTOR_NOMINAL;
    steinhart = log(steinhart);
    steinhart /= B_COEFFICIENT;
    steinhart += 1.0 / (TEMPERATURE_NOMINAL + 273.15);
    steinhart = 1.0 / steinhart;
    steinhart -= 273.15;

    temperatures[i] = steinhart;
  }

  Serial.print(temperatures[0]);
  Serial.print(",");

  Serial.print(temperatures[1]);
  Serial.print(",");

  Serial.print(temperatures[2]);
  Serial.print(",");

  Serial.println(temperatures[3]);

  delay(1000);
}