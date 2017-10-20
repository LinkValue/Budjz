#include <PrintEx.h>

// Analogic
int SENSOR_HUMIDITY = A0;

// Digital
int LED_HUMIDITY_RED = 7;
int LED_HUMIDITY_GREEN = 8;
int LED_HUMIDITY_BLUE = 9;
int BUTTON = 4;

// Constants
int DELAY = 1000;
int RGB_MAX = 250;
int RGB_MIN = 0;

StreamEx serial = Serial;

void setup() {
  Serial.begin(9600);
  pinMode(LED_HUMIDITY_GREEN, OUTPUT);
  pinMode(LED_HUMIDITY_RED, OUTPUT);
  pinMode(LED_HUMIDITY_BLUE, OUTPUT);
  pinMode(BUTTON, INPUT);
  serial.printf( "%20n\nArduino Started!\n%20n\n", '=', '=' );
}

void loop() {
  float humidity = calculHumidity();
  lightUpHumidityLed(humidity);
  logAnalog("Humidity", SENSOR_HUMIDITY, humidity * 100);

  delay(DELAY);
}

float calculHumidity() {
  return (float) (1024 - analogRead(SENSOR_HUMIDITY)) / 1024;
}

void lightUpHumidityLed(float humidity) {
  if (humidity > 0.70) {
    digitalWrite(LED_HUMIDITY_BLUE, RGB_MAX);
    digitalWrite(LED_HUMIDITY_GREEN, RGB_MIN);
    digitalWrite(LED_HUMIDITY_RED, RGB_MIN);
  } else if(humidity > 0.40) {
    digitalWrite(LED_HUMIDITY_BLUE, RGB_MIN);
    digitalWrite(LED_HUMIDITY_GREEN, RGB_MAX);
    digitalWrite(LED_HUMIDITY_RED, RGB_MIN);
  } else {
    digitalWrite(LED_HUMIDITY_BLUE, RGB_MIN);
    digitalWrite(LED_HUMIDITY_GREEN, RGB_MIN);
    digitalWrite(LED_HUMIDITY_RED, RGB_MAX);
  }
}

void logAnalog(char* type, int sensor, float value) {
  serial
    .concat("live time : ").concat(millis() / 1000).concatln("s")
    .repeatln("-", 10)
    .concat(type).concatln(":")
    .concat("sensor value : ").concatln(analogRead(sensor))
    .concat("value : ").concat(value).concatln("%")
    .repeatln("=", 20);
}

