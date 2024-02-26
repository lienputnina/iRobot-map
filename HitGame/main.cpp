/*
Nosacījumi:
• Personāžu var izveidot tikai dzīvu life > 0
• Ja personāžam beidzās dzīvība, tas skaitās par mirušo.
• Mirušam personāžam funkcionē tikai funkcija PrintCharacter(), un protams
~Character(); - how to enforce this?
 Testa personāži: • Jāizveido 2 personāži • vienam ievadīt <10
iešanas virzienus, otram >10 • vienam jāpaliek dzīvam, otro jānogalina :) • Tam
kuru nogalinājāt, mēģināt vēlreiz izsaukt Hit un Go. • Beigās abiem izsaukt
PrintCharacter
*/

#include "Character.h"
#include <iostream>
using namespace std;

int main() {
  string characterName = "TestCharacter1";
  int lifePoints = 10;
  char move;

  Character TestCharacter1(characterName, lifePoints);

  cout << "Which way do you want your character to move? Enter t for top, b "
          "for bottom, l for left and r for right ";
  cin >> move;

  TestCharacter1.go(move);
  TestCharacter1.printCharacterInfo();

  TestCharacter1.hit(3);
  TestCharacter1.getLife();

  cout << "Make another move. Enter t for top, b "
          "for bottom, l for left and r for right ";
  cin >> move;
  TestCharacter1.go(move);
  TestCharacter1.hit(4);
  TestCharacter1.getLife();

  cout << "Make another move. Enter t for top, b "
          "for bottom, l for left and r for right ";
  cin >> move;
  TestCharacter1.go(move);
  cout << "Make another move. Enter t for top, b "
          "for bottom, l for left and r for right ";
  cin >> move;
  TestCharacter1.go(move);
  TestCharacter1.hit(2);
  TestCharacter1.printCharacterInfo();

  cout << "Make another move. Enter t for top, b "
          "for bottom, l for left and r for right ";
  cin >> move;
  TestCharacter1.go(move);
  TestCharacter1.hit(1);
  TestCharacter1.printCharacterInfo();
  return 0;
}