#include "iRobot.h"
#include <iostream>

using namespace std;

int main() {

  {
    iRobot TestRobot1("TestRobot1", 1234, 6789);
    TestRobot1.SwitchOnOff();

    int room[10] = {23, 35, 55, 74, 45, 46, 34, 77, 23, 98};
    TestRobot1.Run(room, 10);

    TestRobot1.PrintRobot();
  }

  cout << "----------" << endl;
  {
    iRobot TestRobot2("TestRobot2", 7777, 8888);
    TestRobot2.SwitchOnOff();

    int room[10] = {23, 35, 55, 74, 45, 47, 34, 77, 23, 98};
    TestRobot2.Run(room, 10);

    TestRobot2.PrintRobot();
  }
  return 0;
}