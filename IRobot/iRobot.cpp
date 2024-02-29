#include "iRobot.h"
#include "ProximitySensor.h"
#include <iostream>
#include <string>
using namespace std;

iRobot::iRobot(string model_name_param, int leftSerialNumber,
               int rightSerialNumber) {
  model_name = model_name_param;
  leftSensor = new ProximitySensor(leftSerialNumber);
  rightSensor = new ProximitySensor(rightSerialNumber);
}

iRobot::~iRobot() {
  delete leftSensor; // Don't forget to delete in destructor
  delete rightSensor;
}

void iRobot::SwitchOnOff() {
  string newState = isRobotOn == true ? "off" : "on";
  leftSensor->SetState(newState);
  rightSensor->SetState(newState);

  isRobotOn = !isRobotOn;

  cout << model_name << " is now " << newState << endl;
};

void iRobot::Run(int room[10], int size) {
  if (!isRobotOn) {
    cout << model_name << " is off. Please turn on before running." << endl;
    return;
  }

  for (int i = 0; i < size; i++) {
    int areaCode = room[i];
    int leftSensorInput = areaCode / 10;
    int rightSensorInput = areaCode % 10;

    bool leftObstacle = leftSensor->Scan(leftSensorInput);
    bool rightObstacle = rightSensor->Scan(rightSensorInput);

    if (!leftObstacle && rightObstacle) {
      map += "l";
    } else if (leftObstacle && !rightObstacle) {
      map += "r";
    } else if (!leftObstacle && !rightObstacle) {
      map += "f";
    } else {
      alarm = "red";
      cout << model_name << " reached a dead-end." << endl;
      return;
    }
  }

  alarm = "green";
  cout << model_name << " cleaned the whole room." << endl;
}

void iRobot::PrintRobot() {
  cout << "The last route made: " << endl;

  for (int i = 0; i < map.length(); i++) {
    cout << map[i];
  }

  cout << endl << "Alarm status: " << alarm << endl;
};