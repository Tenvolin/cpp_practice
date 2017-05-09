
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
  // declare c-style array of strings
  // fill array with strings
  const char *names[] = {"George", "Jorje", "Alex", "John"};
  const int numNames = 4;

  int randInt;

  char answer[255];
  do
  {
    // generate random integer that ranges all valid indices of your array of strings
    //  and seed rand
    std::srand((unsigned)time(0));
    randInt = std::rand() % numNames;

    std::cout << "Name: " << names[randInt] << std::endl;

    // receive user input to continue printing random names
    std::cout << "More names? (y/Y)" << std::endl;
    std::cin >> answer;
    randInt %= numNames;
  } while (answer[0] == 'y' || answer[0] == 'Y');
}