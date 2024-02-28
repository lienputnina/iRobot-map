#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

Character::Character(string characterName, int characterLife) {
  life = characterLife > 10 ? 10 : characterLife;
  name = characterName;
}

Character::~Character() { cout << "Game over for " << name << endl; }

void Character::Go(char move) {
  /*
  Checking whether the character is alive. If the character is dead,
  the method should do nothing.
  */
  if (!IsAlive()) {
    cout << "Cannot move. " << name << " is dead." << endl;
    return;
  }

  // Checking, whether the move is legal
  bool isMoveLegal = move == 't' || move == 'b' || move == 'l' || move == 'r';

  // Checking if the move is legal
  if (isMoveLegal) {
    /*
     If less than 10 moves have been made, the move is saved in the "path" array
     at the position of the current move
    */
    if (moveCount < 10) {
      path[moveCount] = move;
    } else {
      /*
      If more than 10 moves have been made, the elements of the path array are
      shifted one space to the left
      */
      int length = sizeof(path);
      for (int i = 0; i < length; i++) {
        /*
        Skipping the first iteration, since there is no space to move the
        elements to
        */
        if (i == 0) {
          continue;
        }

        /*
        Taking the array element of the current position in the array and
        putting it in the previous position
        */
        path[i - 1] = path[i];
      }

      // Saving the new move to the end of the array
      path[length - 1] = move;
    }

    // Incrementing the number of moves made
    moveCount++;
  } else {
    // Handling an incorrect/illegal move
    cout << "Invalid move. Please enter 't' for top, 'b' for bottom, 'l' for "
            "left, or 'r' for right."
         << endl;
  }
};

bool Character::Hit(int damage) {
  /*
  Checking whether the character is alive. If not
  the method does nothing
  */
  if (!IsAlive()) {
    cout << "Cannot hit. " << name << " is already dead." << endl;
    return false;
  }

  // Decreasing life by the hits taken
  life -= damage;

  cout << "Character got " << damage << " hits." << endl;
  cout << "Is the character alive? " << (IsAlive() ? "Yes." : "No.") << endl;

  return IsAlive();
};

bool Character::IsAlive() { return life > 0 ? true : false; }

int Character::GetLife() { return life; };

// Printing the remaining life points of a character, if they're alive
void Character::PrintLife() {
  if (IsAlive()) {
    cout << "Life points: " << life << endl;
  } else {
    cout << name << " is dead." << endl;
  }
}

void Character::PrintCharacter() {
  string characterState = IsAlive() ? "alive" : "dead";

  cout << "PrintCharacter: " << name << " is " << characterState << endl;
  if (IsAlive()) {
    cout << "Life points: " << life << endl;
  }

  cout << "Last 10 moves: ";

  /*
  Iterating over the moves made and printing only the values of the non-empty
  array positions
  */
  for (int i = 0; i < moveCount; ++i) {
    cout << path[i];
  }

  cout << endl;
}
