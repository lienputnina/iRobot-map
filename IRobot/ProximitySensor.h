#ifndef PROXIMITY_SENSOR_H
#define PROXIMITY_SENSOR_H

#include <string>
using namespace std;

class ProximitySensor {

private:
  string state;
  int serial_number;
  int area;

public:
  ProximitySensor(int serial_number, string state);
  ~ProximitySensor();

  string GetState();
  string SetState();
  bool Scan(int area);
  void PrintSensor();
};

#endif