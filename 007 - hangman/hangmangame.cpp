#include "hangmangame.h"
#include <ctime>
#include <string>
#include <iostream>

Hangman::Hangman()
{
  // roll rand index on [0, WORDBANK_SIZE] and choose word.
  unsigned long rand_index = (time(0) * BIG_NUMBER) % WORDBANK_SIZE;
  std::string word = WORDBANK[rand_index];

  this->life_ = NUM_GUESSES;
  this->word_ = word;
  this->current_index_ = 0;
}
Hangman::~Hangman()
{
}

// purpose: Have user make guess. Returns numbers representing results and
//          game state.
// TODO: Add capability to guess entire word; more than one char; manager fulfill.
// TODO: Choose to overload and receive a string or receive a character.
// in: c: character used to guess current word;
// out: 0 -> dead; 1 -> finished game; 2 -> incorrect guess; 3 -> correct guess;
int Hangman::guess(char guess)
{
  int answer = 0;

  // Increment or decrement life and determine correctness of guess.
  if (this->life_ > 0)
  {
    char compare = this->word_[this->current_index_];
    if (guess == compare)
    {
      ++this->current_index_; // Will exceed allowed index in WIN state.
      (this->current_index_ == this->word_.size()) ? answer = WIN : answer = CORRECT;
    }
    else
    {
      this->life_--;
      (this->life_ <= 0) ? answer = LOSS : answer = INCORRECT;
    }
  }
  else // Life < 0. Game over. Needs a reset
  {
    answer = LOSS;
  }

  return answer;
}

void Hangman::printCorrectlyGuessed()
{
  int print_to = this->current_index_;
  std::string word = this->word_;
  for (int i = 0; i < current_index_; i++)
  {
    std::cout << word[i];
  }
  std::cout << std::endl;
}

std::string Hangman::getWord()
{
  return this->word_;
}

int Hangman::getLife()
{
  return this->life_;
}