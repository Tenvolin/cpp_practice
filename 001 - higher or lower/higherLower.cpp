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
  std::cout << randomInt << std::endl;

  // prompt user for guess and print feedback
  std::cout << "Guess a number from 0 to 100. I'll tell you if the desired number is higher or lower!\n";
  do {
    std::cin >> userGuess;
    if (randomInt > userGuess)
      std::cout << "Higher\n";
    else if (randomInt < userGuess )
      std::cout << "Lower\n";
    else
      break;
  } while(userGuess != randomInt);

  std::cout << "You guessed right!";

}