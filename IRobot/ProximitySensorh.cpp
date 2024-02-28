#include "ProximitySensor.h"
#include <iostream>
#include <string>
using namespace std;

ProximitySensor::ProximitySensor(int robot_serial_number, string robot_state) {
  serial_number = robot_serial_number;
  state = robot_state = "off";
}

string ProximitySensor::GetState() { return state; };

string ProximitySensor::SetState() {
  if (state == "off") {
    state = "on";
  } else if (state == "on") {
    state = "off";
  }
  return state;
};

bool ProximitySensor::Scan(int area) { return area % 2 == 0 ? true : false; }

void ProximitySensor::PrintSensor() {
  cout << "The robot " << serial_number << "is " << GetState() << endl;
  cout << "There are" << (Scan(area) ? "obstacles" : "no obstacles");
}
