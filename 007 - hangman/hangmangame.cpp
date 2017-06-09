#include "hangmangame.h"
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using std::string;
using std::map;
using std::vector;

/* purpose: Initializes game. A single object represents a game.  
 */
Hangman::Hangman()
{
  std::srand(time(0));
  // roll rand index on [0, WORDBANK_SIZE) and choose word.
  unsigned long rand_index = rand() % WORDBANK_SIZE;
  string word = WORDBANK[rand_index];

  this->life_ = NUM_GUESSES;
  this->word_ = word;
  this->current_index_ = 0;
  this->char_indices_map_ = generateCharIndicesMap(this->word_);

  // initialize revealed_
  this->revealed_ = this->word_;
  for (char &c : this->revealed_) {
    c = '_';
  }

}

Hangman::~Hangman()
{
}

/* purpose: Convert the chosen word to constituent chars and the indices
 *          they exist on. 
 */
map<char, vector<int>> Hangman::generateCharIndicesMap(string word)
{
  // Create map.
  char c = '\0';
  map<char, vector<int>> char_map;
  map<char, vector<int>>::iterator it;

  // Iterate over string and check if each char exists.
  for (int i = 0; i < word.size(); ++i) {
    c = word[i];
    it = char_map.find(c);
    
    // Encounter new char: create new pair and create list of indices.
    if (it == char_map.end()) {
      vector<int> indices;
      indices.push_back(i);
      char_map.emplace(c, indices);
    } else { // insert into existing vector
      vector<int> &indices_index = char_map.at(c);
      indices_index.push_back(i);
    }

  }

  return char_map;
}

/* pre: guess is a string holding user's guess.
 * purpose: Have user make guess. Returns numbers representing results and
 *          game state.
 * in: c: character used to guess current word;
 * out: 0 -> LOSS; 1 -> WIN; 2 -> INCORRECT; 3 -> CORRECT; */
int Hangman::guess(string guess)
{
  int answer = 0;

  if (this->life_ > 0 && guess.size() > 1) { // Guess entire word.
    this->guess_word_helper(guess, answer);
    std::cout << "Answer " << answer << std::endl;
  } else if (this->life_ > 0 && guess.size() == 1) { // Guess single char.
    this->guess_char_helper(guess[0], answer);
  } else { // state: LOSS
    answer = LOSS;
  }

  return answer;
}

/*
 * purpose: Helper that handles single-character guesses.
 * in: One output parameter.
 * out: N/A.
*/
void Hangman::guess_char_helper(char guess_char, int &answer)
{
  vector<int> results;
  map<char, vector<int>> &char_indices_map = this->char_indices_map_;
  auto it = char_indices_map.find(guess_char);

  if (it != char_indices_map.end()) { // Correct guess.
    updateRevealed(it->first, it->second);
    (this->word_ == this->revealed_) ? answer = WIN : answer = CORRECT;
  } else { // Wrong guess. 
    // check if we become dead; else return INCORRECT.
    --this->life_;
    (this->life_ <= 0) ? answer = LOSS : answer = INCORRECT;
  }
}

/*
 * purpose: Helper that handles multi-character guesses.
 * in: One output parameter.
 * out: N/A.
 */
void Hangman::guess_word_helper(string guess, int &answer)
{
  std::cout << guess << " VS " << this->word_ << std::endl;
  (guess == this->word_) ? answer = WIN : (--this->life_, answer = INCORRECT);
  std::cout << "Answer " << answer << std::endl;
}

/* purpose: Update indices of our masked word with the letter.
 * in: c: individual chars. Indices: represent indices in which a char exists.*/
void Hangman::updateRevealed(char c, vector<int> indices)
{
  for (auto index : indices) {
    this->revealed_[index] = c;
  }
}

/* purpose: Print current guess status. Chosen word is initialized with _'s
 *          in the place of each letter; each letter is unmasked with guesses.*/
void Hangman::printCorrectlyGuessed()
{
  std::cout << this->revealed_ << std::endl;
}

void Hangman::printWord()
{
  std::cout << this->word_ << std::endl;
}

/* purpose: Print each character with indices they exist on.*/
void Hangman::printCharMapSummary()
{
  auto charMap = this->getCharMap();
  for (auto it = charMap.begin(); it != charMap.end(); ++it) {

    std::cout << it->first << "-indices: ";
    
    for (auto &index : it->second) {
      std::cout << index << '.';
    }
    std::cout << std::endl;
  }
}

std::string Hangman::getWord()
{
  return this->word_;
}

int Hangman::getLife()
{
  return this->life_;
}

map<char, vector<int>> Hangman::getCharMap()
{
  return this->char_indices_map_;
}
