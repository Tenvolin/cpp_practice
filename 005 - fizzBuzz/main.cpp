#include <iostream>

// purpose: Simple implementation of fizzbuzz.
// notes: Print every number out; if evenly divisible by 3, print fizz. If it's 
//        evenly divisible by 5 print buzz; if both evenly divisible by 3 and 5,
//        print fizz buzz.
int main()
{
  for (int i = 1; i < 100; i++)
  {
    if (i % 3 == 0)
    {

      std::cout << "Fizz";

      if (i % 5 == 0)
        std::cout << " Buzz, ";
      else
        std::cout << ", ";
    }
    else
      std::cout << i << ", ";
  }
}