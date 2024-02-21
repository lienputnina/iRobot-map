#include "Character.h";
#include <iostream>;
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

bool Character::hit(int hitsTaken) {

  lifePoints -= hitsTaken;
  bool isAlive = lifePoints > 0 && lifePoints <= 10 ? true : false;

  return isAlive;
};

int Character::getLife() { return lifePoints; };

void Character::go(char) {
  string move;
  cout << "Which way do you want your character to move? The options are t for "
          "top, "
          "b for bottom, l for left and r for right";
  cin >> move;
  movePath; // figure out, how to add elements to it;
};

void Character::printCharacterInfo() {
  string characterState = lifePoints > 0 && lifePoints <= 10 ? "alive" : "dead";

  cout << characterName << "is" << characterState << endl;
  cout << "Last 10 moves: " << movePath;
}
