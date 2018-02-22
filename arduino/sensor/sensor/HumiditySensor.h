#include "./Sensor.h"

class HumiditySensor : public Sensor
{
  public:
    HumiditySensor(int ai):Sensor(ai) {};
    float value();
  protected:
    float calcul();
};

float HumiditySensor::value() {
  lastValue = calcul();
  return lastValue;
}

float HumiditySensor::calcul() {
  return (float) (1024 - analogRead(analogInput)) / 1024;
}
