#ifndef HANGMAN_GAME
#define HANGMAN_GAME

#include <string>
// game states for guess()
const int LOSS = 0;
const int WIN = 1;
const int INCORRECT = 2;
const int CORRECT = 3;
const int BIG_NUMBER = 2251;
// general constants
const unsigned NUM_GUESSES = 10;
const unsigned WORDBANK_SIZE = 5;
const std::string WORDBANK[WORDBANK_SIZE] = {"hello", "dog", "god", "meme", "dumb"};


// purpose: Represents a hangman game. Holds the state of game. Each game
//          Has a allotted number of guesses.
// input: none;
// output: none;
class Hangman {
private:
  std::string word_;
  unsigned current_index_; // current_index_ is not revealed(guessed correctly) yet.
  unsigned life_;

public:
  int guess(char c);
  int getLife();
  std::string getWord();
  void printCorrectlyGuessed();
  
  Hangman();
  ~Hangman();
};


#endif // end HANGMAN_GAME