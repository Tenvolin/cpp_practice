#ifndef HANGMAN_GAME
#define HANGMAN_GAME

#include <string>
#include <map>
#include <vector>
using std::string;
using std::map;
using std::vector;
// game states for guess()
const int LOSS = 0;
const int WIN = 1;
const int INCORRECT = 2;
const int CORRECT = 3;
const int BIG_NUMBER = 2253;
// general constants
const unsigned NUM_GUESSES = 10;
const unsigned WORDBANK_SIZE = 5;
const string WORDBANK[WORDBANK_SIZE] = {"hello", "dog", "god", "meme", "dumb"};


// purpose: Represents a hangman game. Holds the state of game. Each game
//          Has a allotted number of guesses.
// input: none;
// output: none;
class Hangman {
private:
  string word_;
  string revealed_; // all _'s representing the masked word.
  unsigned current_index_; // current_index_ is not revealed(guessed correctly) yet.
  unsigned life_; // number of guesses remaining.
  // The map holds chars mapped to indices.
  map<char, vector<int>> char_indices_map_; 

  map<char, vector<int>> generateCharIndicesMap(string word);
  void updateRevealed(char c, vector<int> indices);
  map<char, vector<int>> getCharMap();
  void printCharMapSummary();

public:
  int getLife();
  string getWord();
  int guess(char c);
  void printCorrectlyGuessed();
  
  Hangman();
  ~Hangman();
};


#endif // end HANGMAN_GAME