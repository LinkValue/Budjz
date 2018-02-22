class Sensor {
  public:
    explicit
    Sensor(int ai):analogInput(ai) {};
    virtual float value();
  protected:
    int analogInput;
    float lastValue;
};
