#include <iostream>
#include <string>
#include <cstdio>

/* purpose: Calculate love rating between two people's names.
 * note: self made algorithm.
*/ 
int calculate_love(std::string name1, std::string name2)
{
  // algorithm: Sum ascii codes of each name, modulo the product of sum1 and sum2.
  int sum1 = 0, sum2 = 0;
  int product = 1;
  
  for (int ascii : name1)
    sum1 += ascii;
  for (int ascii : name2)
    sum2 += ascii;
  
  product = sum1 * sum2;
  
  product %= 100;

  return product;
}

/* Receive prompts for two names and calculate love rating between two people!*/
int main()
{
  std::string name1 = "", name2 = "";

  printf("Please give me a name!\n");
  getline(std::cin, name1);
  printf("Please give me another name!\n");
  getline(std::cin, name2);

  int result = calculate_love(name1, name2);
  printf("Result: %i", result);
}