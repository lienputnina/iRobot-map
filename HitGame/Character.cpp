#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

Character::Character(string characterNameP, int lifeP) { // rename the P words
  life = lifeP > 10 ? 10 : lifeP;
  name = characterNameP;
  moveCount = 0;
}

Character::~Character() { cout << "Game over for " << name << endl; }

void Character::Go(char move) {
  if (!IsAlive()) {
    cout << "Cannot move. " << name << " is dead." << endl;
    return;
  }

  // checking, whether move is legal
  bool isMoveLegal = move == 't' || move == 'b' || move == 'l' || move == 'r';

  if (isMoveLegal) {
    if (moveCount < 10) {
      path[moveCount] = move; // tajā pozicija, kurs moves tgd ir
    } else {
      int length = sizeof(path);
      // Shift moves array to the left by one
      for (int i = 0; i < length; i++) {
        if (i == 0) { // pirmo izlaižam, jo nav, kur aizbīdīt
          continue;
        }

        path[i - 1] = path[i]; // paņem patreizējās pozīcijas elementu (masīva
                               // elementu) un ievietojam iepriekšējā pozīcijā
      }

      path[length - 1] = move; // saglabājam jauno gājienu
    }
    moveCount++;
  } else {
    cout << "Invalid move. Please enter 't' for top, 'b' for bottom, 'l' for "
            "left, or 'r' for right."
         << endl;
  }
};

bool Character::Hit(int hitsTaken) {
  if (!IsAlive()) {
    cout << "Cannot hit. " << name << " is already dead." << endl;
    return false; // will this work correctly?
  }

  life -= hitsTaken;

  cout << "Character got " << hitsTaken << " hits." << endl;
  cout << "Is the character alive? " << (IsAlive() ? "Yes." : "No.") << endl;

  return IsAlive();
};

bool Character::IsAlive() { return life > 0 ? true : false; }

int Character::GetLife() { return life; };

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
  for (int i = 0; i < moveCount; ++i) {
    cout << path[i];
  }

  cout << endl;
}
