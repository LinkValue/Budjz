

class BrightnessSensor : public Sensor
{
  public:
    BrightnessSensor(int ai):Sensor(ai) {};
    float value();
  protected:
    float calcul();
};

float BrightnessSensor::value() {
  lastValue = calcul();
  return lastValue;
}

float BrightnessSensor::calcul() {
  Serial.println(analogRead(analogInput));
  return (float) (1024 - analogRead(analogInput)) / 1024;
}
