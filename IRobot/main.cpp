#include "iRobot.h"
#include <iostream>

using namespace std;

int main() {

  /*
Dividing the code for both robots in separate blocks for clarity.
*/

  {
    /*
    Instantiating the first object of the iRobot class with arguments
    */
    iRobot TestRobot1("TestRobot1", 1234, 6789);

    // Switching the robot on
    TestRobot1.SwitchOnOff();

    /*
    Initializing the room array. This robot should reach a dead end at some
    point, so there is a number where both digits are even
    */
    int room[10] = {23, 35, 55, 74, 45, 46, 34, 77, 23, 98};
    TestRobot1.Run(room, 10);

    TestRobot1.PrintRobot();
  }

  cout << "----------" << endl;
  {
    /*
   Instantiating the second object of the iRobot class with arguments
   */
    iRobot TestRobot2("TestRobot2", 7777, 8888);

    // Switching the robot on
    TestRobot2.SwitchOnOff();

    /*
       Initializing the room array. This robot should clean the whole room, so
       there are no numbers with both even digits.
       */
    int room[10] = {23, 35, 55, 74, 45, 47, 34, 77, 23, 98};
    TestRobot2.Run(room, 10);

    TestRobot2.PrintRobot();
  }
  return 0;
}