#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character {

private:
  string characterName;
  string characterState;

  int lifePoints;

  char movePath[10] = {};

public:
  Character(string characterName, int lifePoints);
  ~Character();

  bool hit(int);
  int getLife();
  void go(char move);
  void printCharacterInfo();
  bool isAlive();
  void printLife();
  int moveCount = 0;
};

#endif