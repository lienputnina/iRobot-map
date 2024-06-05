#include "ProximitySensor.h"
#include <iostream>
#include <string>
using namespace std;

ProximitySensor::ProximitySensor(int serial_number_param) {
  serial_number = serial_number_param;
  state = "off";
}

string ProximitySensor::GetState() { return state; }

// Assigning the new state to the robot state
void ProximitySensor::SetState(string newState) { state = newState; }

/*
Method returns true when the provided number is even, false if it is odd
*/
bool ProximitySensor::Scan(int area) { return area % 2 == 0; }

// Returns the state of the robot's sensors
void ProximitySensor::PrintSensor() {
  cout << "The robot " << serial_number << " is " << GetState() << ". ";
}