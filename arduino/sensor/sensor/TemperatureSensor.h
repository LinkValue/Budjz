
class TemperatureSensor : public Sensor
{
  public:
    TemperatureSensor(int ai):Sensor(ai) {};
    float value();
  protected:
    float calcul();
};

float TemperatureSensor::value() {
  lastValue = calcul();
  return lastValue;
}

float TemperatureSensor::calcul() {
  Serial.println(analogRead(analogInput));
  return (float) (1024 - analogRead(analogInput)) / 1024;
}
