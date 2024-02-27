#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor with an initialization list
Character::Character(string characterNameP, int lifePointsP) {
  lifePoints = lifePointsP > 10 ? 10 : lifePointsP;
  characterName = characterNameP;
  moveCount = 0;
}

Character::~Character() { cout << "Game over for " << characterName << endl; }

void Character::go(char move) {
  if (!isAlive()) {
    cout << "Cannot move. " << characterName << " is dead." << endl;
    return;
  }

  bool isMoveLegal = move == 't' || move == 'b' || move == 'l' || move == 'r';

  if (isMoveLegal) {
    if (moveCount < 10) {
      movePath[moveCount] = move;
    } else {
      int length = sizeof(movePath);
      // Shift moves array to the left by one
      for (int i = 0; i < length; i++) {
        if (i == 0) {
          continue;
        }

        movePath[i - 1] = movePath[i];
      }

      movePath[length - 1] = move;
    }
    moveCount++;
  } else {
    cout << "Invalid move. Please enter 't' for top, 'b' for bottom, 'l' for "
            "left, or 'r' for right."
         << endl;
  }
};

bool Character::hit(int hitsTaken) {
  if (lifePoints <= 0) {
    cout << "Cannot hit. " << characterName << " is already dead." << endl;
    return false;
  }

  lifePoints -= hitsTaken;

  cout << "Character got " << hitsTaken << " hits." << endl;
  cout << "Is the character alive? " << (isAlive() ? "Yes." : "No.") << endl;

  return isAlive();
};

bool Character::isAlive() { return lifePoints > 0 ? true : false; }

int Character::getLife() { return lifePoints; };

void Character::printLife() {
  if (isAlive()) {
    cout << "Life points: " << lifePoints << endl;
  } else {
    cout << characterName << " is dead." << endl;
  }
}

void Character::printCharacterInfo() {
  string characterState = isAlive() ? "alive" : "dead";

  cout << "PrintCharacter: " << characterName << " is " << characterState
       << endl;
  if (isAlive()) {
    cout << "life points: " << lifePoints << endl;
  }

  cout << "Last 10 moves: ";
  for (int i = 0; i < moveCount; ++i) {
    cout << movePath[i];
  }

  cout << endl;
}
