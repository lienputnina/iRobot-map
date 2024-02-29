#ifndef PROXIMITY_SENSOR_H
#define PROXIMITY_SENSOR_H

#include <string>
using namespace std;

class ProximitySensor {

private:
  string state; // "on" / "off"
  int serial_number;

public:
  ProximitySensor(int serial_number);
  string GetState();
  void SetState(string newState);
  bool Scan(int area);
  void PrintSensor();
};

#endif