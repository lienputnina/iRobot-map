#ifndef IROBOT_H
#define IROBOT_H

#include "ProximitySensor.h"
#include <string>
using namespace std;

class iRobot {

private:
  string model_name;
  ProximitySensor *leftSensor;
  ProximitySensor *rightSensor;
  string alarm = "green"; // "red" / "green"
  string map = "";

  bool isRobotOn = false;

public:
  iRobot(string model_name, int leftSerialNumber, int rightSerialNumber);
  ~iRobot();
  void SwitchOnOff();
  void Run(int room[10], int size);
  void PrintRobot();
};

#endif