#include "hangmangame.h"
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;
using std::cin;

int main()
{
  Hangman game;

  std::string input = "";
  int game_state = -1;

  while (game_state != LOSS && game_state != WIN)
  {
    // Print guesses remaining and guess status of current word.
    system("CLS");
    cout << "You have " << game.getLife() << " guesses remaining." << endl;

    game.printCorrectlyGuessed();

    do
    {
      cout << "Please guess a character:";
      cin >> input;
    } while (input.size() != 1);
    // Pompt user guess and provide feedback.
    game_state = game.guess(input[0]);
  }

  system("CLS");
  game.printCorrectlyGuessed();
  if (game_state == CORRECT)
    cout << "You guessed the right letter!" << endl;
  else if (game_state == INCORRECT)
    cout << "You guessed the wrong letter!" << endl;

  if (game_state == LOSS)
    cout << "You lost the game!" << endl;
  else if (game_state == WIN)
    cout << "You won the game!" << endl;
  

  return 0;
}
