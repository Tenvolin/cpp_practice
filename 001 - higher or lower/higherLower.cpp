#include <stdlib.h>
#include <iostream>
#include <time.h>

// when do we import each of the libraries?
// what are namespaces and how do they work?
int main() {
  
  int maxNumber = 101; // // generate random number on [0, 100]
  int randomInt;
  int userGuess;

  srand( time(0) );
  randomInt = rand() * RAND_MAX % maxNumber;

  // prompt user for guess and print feedback
  std::cout << "Guess a number from 0 to 100. I'll tell you if you're higher or lower!\n";
  do {
    std::cin >> userGuess;
    if (userGuess > randomInt)
      std::cout << "Higher\n";
    else if (userGuess < randomInt)
      std::cout << "Lower\n";
  } while(userGuess != randomInt);

  std::cout << "You guessed right!";

}