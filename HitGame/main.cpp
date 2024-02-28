#include "Character.h"
#include <iostream>
using namespace std;

int main() {
  /*
   Declaring a global "move" variable. This will be used to store the move value
   entered by the user
  */
  char move;

  /*
  Dividing the code for both characters in separate blocks.
  This was done to trigger the destructor for each class instance separately,
  before the program has ended
  */
  {
    /*
    Instantiating the first object of the Character class with the provided
    parameters
    */
    Character TestCharacter1("TestCharacter1", 10);
    /*
    The character should make less than 10 moves, so they're given a maximum
    of 5 moves.
    While the character has made less than 5 moves and they're still alive,
    they move and can get hit. During each iteration, the moves are counted to
    check how many moves have been made
     */
    while (TestCharacter1.moveCount < 5 && TestCharacter1.IsAlive()) {
      cout << "Move " << (TestCharacter1.moveCount + 1)
           << ": Which way do you want your character to move? "
           << "Enter t for top, b for bottom, l for left, and r for right: ";
      cin >> move;

      // Character makes a move with the move value entered by the user
      TestCharacter1.Go(move);

      /*
      The hits are only given, if the number of life points is at least 1.
      because the character should not die.
      */
      if (TestCharacter1.GetLife() > 1) {
        TestCharacter1.Hit(1);
      }
      // If the character is dead, the game ends
      if (!TestCharacter1.IsAlive()) {
        cout << "Character is dead. Game over." << endl;
        break;
      }
    }

    TestCharacter1.PrintCharacter();
  }

  cout << "--------------" << endl;

  {
    // Instantiating the second object of the Character class
    Character TestCharacter2("TestCharacter2", 10);
    /*
      The character should make more than 10 moves, so they're given a maximum
      of 15 moves.
    */
    while (TestCharacter2.moveCount < 15 && TestCharacter2.IsAlive()) {
      cout << "Move " << (TestCharacter2.moveCount + 1)
           << ": Which way do you want your character to move? "
           << "Enter t for top, b for bottom, l for left, and r for right: ";
      cin >> move;
      TestCharacter2.Go(move);

      /*
      Character gets hit only, if they've made more than or equal to 12 moves.
      This is to guarantee at least 10 moves
      */
      if (TestCharacter2.moveCount >= 12) {
        TestCharacter2.Hit(5);
      }

      if (!TestCharacter2.IsAlive()) {
        cout << "Character is dead. Game over." << endl;
        break;
      }
    }

    // Checking, if a dead character can get hits and make a move
    TestCharacter2.Hit(1);
    TestCharacter2.Go('t');

    TestCharacter2.PrintCharacter();
  }

  return 0;
}