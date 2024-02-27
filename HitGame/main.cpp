#include "Character.h"
#include <iostream>
using namespace std;

int main() {
  char move;

  {
    string firstCharacterName = "TestCharacter1";
    int firstCharacterLives = 10;

    Character TestCharacter1(firstCharacterName, firstCharacterLives);
    while (TestCharacter1.moveCount < 5 && TestCharacter1.isAlive()) {
      cout << "Move " << (TestCharacter1.moveCount + 1)
           << ": Which way do you want your character to move? "
           << "Enter t for top, b for bottom, l for left, and r for right: ";
      cin >> move;
      TestCharacter1.go(move); // Character makes a move

      if (TestCharacter1.getLife() > 1) {
        TestCharacter1.hit(1);
      }

      if (!TestCharacter1.isAlive()) {
        cout << "Character is dead. Game over." << endl;
        break;
      }
    }

    TestCharacter1.printCharacterInfo();
  }

  cout << "--------------" << endl;

  {
    string secondCharachterName = "TestCharacter2";
    int secondCharachterLives = 10;

    Character TestCharacter2(secondCharachterName, secondCharachterLives);
    while (TestCharacter2.moveCount < 15 && TestCharacter2.isAlive()) {
      cout << "Move " << (TestCharacter2.moveCount + 1)
           << ": Which way do you want your character to move? "
           << "Enter t for top, b for bottom, l for left, and r for right: ";
      cin >> move;
      TestCharacter2.go(move); // Character makes a move

      if (TestCharacter2.moveCount >= 12) {
        TestCharacter2.hit(5);
      }

      if (!TestCharacter2.isAlive()) {
        cout << "Character is dead. Game over." << endl;
        break;
      }
    }

    TestCharacter2.hit(1);
    TestCharacter2.go('t');

    TestCharacter2.printCharacterInfo();
  }

  return 0;
}