#include "iRobot.h"
#include "ProximitySensor.h"
#include <iostream>
#include <string>
using namespace std;

iRobot::iRobot(string model_name_param, int leftSerialNumber,
               int rightSerialNumber) {
  model_name = model_name_param;

  /*
  Initializing the sensors as instances of the ProximitySensor class
  */
  leftSensor = new ProximitySensor(leftSerialNumber);
  rightSensor = new ProximitySensor(rightSerialNumber);
}

// Freeing up memory after the sensors are no longer used
iRobot::~iRobot() {
  delete leftSensor;
  delete rightSensor;
}

void iRobot::SwitchOnOff() {
  // Determining the new state
  string newState = isRobotOn == true ? "off" : "on";

  /*
  Accessing the SetState method through pointers
  */
  leftSensor->SetState(newState);
  rightSensor->SetState(newState);

  // Setting the new state
  isRobotOn = !isRobotOn;

  cout << model_name << " is now " << newState << endl;
};

/*
The size parameter is required to loop through the whole room array
*/
void iRobot::Run(int room[10], int size) {
  // Cancel the method if the robot is not on
  if (!isRobotOn) {
    cout << model_name << " is off. Please turn on before running." << endl;
    return;
  }

  // Loop through all of the room entries
  for (int i = 0; i < size; i++) {
    int areaCode = room[i];

    /*
    Spliting the provided number in to tens and ones for each sensor
    */
    int leftSensorInput = areaCode / 10;
    int rightSensorInput = areaCode % 10;

    bool leftObstacle = leftSensor->Scan(leftSensorInput);
    bool rightObstacle = rightSensor->Scan(rightSensorInput);

    /*
    Checking for obstacles.
    If there's an obstacle to the left and not to the right the robot moves to
    the right

    If there's an obstacle to the right and no to the left the robot moves to
    the right

    If there are no obstacles on both sides the robot moves forward.

    If there are obstacles on both sides, the robot reaches a dead end and stops
    */
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

// Printing the last route made
void iRobot::PrintRobot() {
  cout << "The last route made: " << endl;

  for (int i = 0; i < map.length(); i++) {
    cout << map[i];
  }

  cout << endl << "Alarm status: " << alarm << endl;
};