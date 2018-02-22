#include <PrintEx.h>
#include "./conf.h"
#include "./sensor/HumiditySensor.h"
#include "./sensor/TemperatureSensor.h"
#include "./sensor/BrightnessSensor.h"

StreamEx serial = Serial;
HumiditySensor humiditySensor = HumiditySensor(SENSOR_HUMIDITY);
TemperatureSensor temperatureSensor = TemperatureSensor(SENSOR_TEMPERATURE);
BrightnessSensor brightnessSensor = BrightnessSensor(SENSOR_BRIGHTNESS);

void setup() {
  Serial.begin(9600);

  pinMode(LED_HUMIDITY_GREEN, OUTPUT);
  pinMode(LED_HUMIDITY_RED, OUTPUT);
  pinMode(LED_HUMIDITY_BLUE, OUTPUT);

  serial.printf( "%20n\nArduino Started!\n%20n\n", '=', '=' );
}

void loop() {
  serial.printf( "\nLoop!\n%20n\n", '=' );

  Serial.println("humiditySensor");
  Serial.println(humiditySensor.value());
  Serial.println("temperatureSensor");
  Serial.println(temperatureSensor.value());
  Serial.println("brightnessSensor");
  Serial.println(brightnessSensor.value());

  delay(DELAY);
}

void lightUpHumidityLed(float humidity) {
  if (humidity > 0.70) {
    digitalWrite(LED_HUMIDITY_BLUE, RGB_MAX);
    digitalWrite(LED_HUMIDITY_GREEN, RGB_MIN);
    digitalWrite(LED_HUMIDITY_RED, RGB_MIN);
  } else if (humidity > 0.40) {
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
  .repeatln("-", 20)
  .concat(type).concatln(":")
  .concat("sensor value : ").concatln(analogRead(sensor))
  .concat("value : ").concat(value).concatln("%")
  .repeatln("=", 20);
}

