#ifndef IROBOT_H
#define IROBOT_H

#include <string>
using namespace std;

class iRobot {

private:
  string model_name;
  int leftSensor;
  int rightSensor;
  string alarm;
  string map[10] = {}; // is this an array?

public:
  iRobot(string model_name, string alarm); // kas ir te?
  ~iRobot();

  bool SwitchOnOff(int leftSensor, int rightSensor);
  int Run(int room);
  void PrintRobot();

  int room[10] = {}; // declare here or in the method?
  int turnCount = 0;
};

#endif