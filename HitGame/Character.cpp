#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor with an initialization list
Character::Character(string characterName, int lifePoints)
    /*
    initializes the class's member variables with the values of the parameters
    passed to the constructor.
    the class's member variable is being initialized with the value of the
    constructor's parameter.
    */
    : characterName(characterName), lifePoints(lifePoints), moveCount(0) {}

Character::~Character() { cout << "Game over for " << characterName; }

void Character::go(char move) {
  if (moveCount < 10 &&
      (move == 't' || move == 'b' || move == 'l' || move == 'r')) {
    movePath[moveCount] = move;
    moveCount++;
  } else {
    if (moveCount >= 10) {
      cout << "No more space to record moves." << endl;
    } else {
      cout << "Invalid move. Please enter 't' for top, 'b' for bottom, 'l' for "
              "left, or 'r' for right."
           << endl;
    }
  }
};

bool Character::hit(int hitsTaken) {

  lifePoints -= hitsTaken;
  bool isAlive = (lifePoints > 0) && (lifePoints <= 10);

  cout << "Is the character alive? " << (isAlive ? "Yes" : "No") << endl;

  return isAlive;
};

int Character::getLife() { return lifePoints; };

void Character::printCharacterInfo() {
  string characterState = lifePoints > 0 && lifePoints <= 10 ? "alive" : "dead";

  cout << characterName << "is" << characterState << endl;
  cout << "Last 10 moves: " << movePath;
}
