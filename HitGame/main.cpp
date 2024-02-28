#include "Character.h"
#include <iostream>
using namespace std;

int main() {
  char move;

  {
    string characterOneName = "TestCharacter1";
    int characterOneLife = 10;

    Character TestCharacter1(characterOneName, characterOneLife);
    while (TestCharacter1.moveCount < 5 && TestCharacter1.IsAlive()) {
      cout << "Move " << (TestCharacter1.moveCount + 1)
           << ": Which way do you want your character to move? "
           << "Enter t for top, b for bottom, l for left, and r for right: ";
      cin >> move;
      TestCharacter1.Go(move); // Character makes a move

      if (TestCharacter1.GetLife() > 1) {
        TestCharacter1.Hit(1);
      }

      if (!TestCharacter1.IsAlive()) {
        cout << "Character is dead. Game over." << endl;
        break;
      }
    }

    TestCharacter1.PrintCharacter();
  }

  cout << "--------------" << endl;

  {
    string characterTwoName = "TestCharacter2";
    int characterTwoLife = 10;

    Character TestCharacter2(characterTwoName, characterTwoLife);
    while (TestCharacter2.moveCount < 15 && TestCharacter2.IsAlive()) {
      cout << "Move " << (TestCharacter2.moveCount + 1)
           << ": Which way do you want your character to move? "
           << "Enter t for top, b for bottom, l for left, and r for right: ";
      cin >> move;
      TestCharacter2.Go(move); // Character makes a move

      if (TestCharacter2.moveCount >= 12) {
        TestCharacter2.Hit(5);
      }

      if (!TestCharacter2.IsAlive()) {
        cout << "Character is dead. Game over." << endl;
        break;
      }
    }

    TestCharacter2.Hit(1);
    TestCharacter2.Go('t');

    TestCharacter2.PrintCharacter();
  }

  return 0;
}