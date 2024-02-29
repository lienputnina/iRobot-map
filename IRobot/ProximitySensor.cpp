#include "ProximitySensor.h"
#include <iostream>
#include <string>
using namespace std;

ProximitySensor::ProximitySensor(int serial_number_param) {
  serial_number = serial_number_param;
  state = "off";
}

string ProximitySensor::GetState() { return state; }

void ProximitySensor::SetState(string newState) { state = newState; }

// Even number is an obstacle, returns if there is an obstacle
bool ProximitySensor::Scan(int area) { return area % 2 == 0; }

void ProximitySensor::PrintSensor() {
  cout << "The robot " << serial_number << " is " << GetState() << ". ";
}