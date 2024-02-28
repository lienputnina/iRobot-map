#include "iRobot.h"
#include <iostream>
#include <string>
using namespace std;

iRobot::iRobot(string robot_model_name, string robot_alarm) {
  string model_name = robot_model_name;
  string alarm = robot_alarm;
}

bool iRobot::SwitchOnOff(int leftSensor, int rightSensor) {
  // turns on the robot by turning on both sensors
  // how does it work?
  bool isRobotOn; // what are the conditions for this?
  return isRobotOn;
};

int iRobot::Run(int room) {
  /*
  if(!on) {
      cout << "Cannot run. Robot turned off"
  }
  */
  // Loops through the room array and processes its elements
  // First digit for leftSensor, second digit for rightSensor
  int roomLength = sizeof(room);

  for (int i = 0; i < roomLength; i++) {
    // go through numbers and split them into digits, assign them to the sensors

    // conditional flow for getting directions
    if (leftSensor % 2 != 0 && rightSensor % 2 == 0) {
      map[i] = "l";
    } else if (leftSensor % 2 == 0 && rightSensor % 2 != 0) {
      map[i] = "r";
    } else if (leftSensor % 2 != 0 && rightSensor % 2 != 0) {
      map[i] = "f";
    }

    // condition for dead end and alarm
    if (leftSensor % 2 == 0 && rightSensor % 2 == 0) {
      cout << model_name << "reached a dead-end" << endl;
      alarm = "red";
    } else {
      alarm = "green";
      cout << model_name << "cleaned the whole room" << endl;
    }
  };

  return smsms;
};

void iRobot::PrintRobot() {
  cout << "The last route made" << map << endl;
  for (int i = 0; i < turnCount; ++i) {
    cout << map[i];
  }

  cout << "Alarm status" << alarm; // is this correct?
}