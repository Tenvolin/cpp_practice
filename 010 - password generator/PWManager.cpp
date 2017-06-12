#include <iostream>
#include "PWManager.h"
#include <vector>
#include <string>

/* PURPOSE: Class containing members that correspond to character maps. If a 
*  member is true, the corresponding character set will be available to roll for.
*/
PWManager::PWManager()
{
  this->symbols_ = true;
  this->numbers_ = true;
  this->lower_case_ = true;
  this->upper_case_ = true;
  this->pw_length_ = PW_LENGTH;
}

/* PURPOSE: Loop through PWManager members and determine what chracter sets are
 * to be used for password generation.
 * OUTPUT: Vector containing all true members for pw generation.
*/
std::vector<unsigned> PWManager::OptionsToRoll()
{
  std::vector<unsigned> vec;

  // iterate through PWManager members
  if (this->symbols_)
    vec.push_back(SYMBOLS);
  if (this->numbers_)
    vec.push_back(NUMBERS);
  if (this->lower_case_)
    vec.push_back(LOWER);
  if (this->upper_case_)
    vec.push_back(UPPER);

  return vec;
}

/* PURPOSE: Set length of password.
 * INPUT: Int representing length.
 * OUTPUT:  Negative length outputs -1;
 *          Error outputs 0;
 *          No errors - proper set: 1.
*/
int PWManager::length(int length)
{
  int answer;
  (length < 0) ? answer = -1 : answer = 1;

  this->pw_length_ = length;
  return answer;
}

/* PURPOSE: Assign value
 * INPUT: _IN_ user_option
*/
void getUserInput(int &user_option)
{
  std::string input_str;
  bool allDecimal = true;

  // Receive user input and ensure decimals only in input_str.
  do {
    allDecimal = true;
    getline(std::cin, input_str);

    // loop if not all characters  
    for (char c : input_str) {
      if (c < 48 || c > 57) {
        allDecimal = false;
        break;
      }
    }
  } while(!allDecimal);

  user_option = std::stoi(input_str); 
  std::cout << "MEME HERE: " << user_option << std::endl; 
}