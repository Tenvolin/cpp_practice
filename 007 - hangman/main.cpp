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

  while (game_state != LOSS && game_state != WIN) {
    // Print guesses remaining and guess status of current word.
    cout << "You have " << game.getLife() << " guesses remaining." << endl;
    game.printCorrectlyGuessed();

    // Read input and process
    cout << "Please guess a character or word: ";
    cin >> input;
    game_state = game.guess(input);

    // Clear screen and update user on status.
    // TODO: Update on single char or entire guess.
    system("CLS");
    if (game_state == CORRECT)
      cout << "You guessed correctly!" << endl;
    else if (game_state == INCORRECT)
      cout << "You guessed incorrectly!" << endl;
      
  }

  system("CLS");
  game.printWord();

  if (game_state == LOSS)
    cout << "You lost the game!" << endl;
  else if (game_state == WIN)
    cout << "You won the game!" << endl;

  return 0;
}
