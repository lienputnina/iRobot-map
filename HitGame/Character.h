#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character {

private:
  string name;
  int life;

  char path[10] = {};

public:
  Character(string name, int life);
  ~Character();

  bool Hit(int);
  int GetLife();
  void Go(char move);
  void PrintCharacter();
  bool IsAlive();
  void PrintLife();
  int moveCount = 0;
};

#endif