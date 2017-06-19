#include <iostream>
#include "PWManager.h"
#include <vector>
#include <string>
#include <map>
#include <ctime>

/* PURPOSE: Class containing members that correspond to character maps. If a 
*  member is true, the corresponding character set will be available to roll for.
*/
PWManager::PWManager()
{
  this->symbols_ = true;
  this->numbers_ = true;
  this->lower_ = true;
  this->upper_ = true;
  this->length_ = PW_LENGTH;
  initCharRanges();
}

/* PURPOSE: Loop through PWManager members and determine what character sets are
 * to be used for password generation.
 * OUTPUT: Vector containing all true members for pw generation.
*/
std::vector<unsigned> PWManager::optionsToRoll()
{
  std::vector<unsigned> vec;

  // iterate through PWManager members
  if (this->symbols_)
    vec.push_back(SYMBOLS);
  if (this->numbers_)
    vec.push_back(NUMBERS);
  if (this->lower_)
    vec.push_back(LOWER);
  if (this->upper_)
    vec.push_back(UPPER);

  return vec;
}

/* PURPOSE: Set length of password.
 * INPUT: Int representing length.
 * OUTPUT:  Negative length outputs 0;
 *          No errors - proper set: 1.
*/
int PWManager::length(int length)
{
  int answer;
  (length < 0) ? answer = -1 : answer = 1;

  this->length_ = length;
  return answer;
}

/* PURPOSE: Assign value
 * INPUT: user_option is an input parameter.
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
}

/* PURPOSE: Load all character ranges into map and seeds RAND.
 * NOTE: Might not need this fn at all; just for clarity's sake in code?
 *       Should it be defined as a const as opposed to creating on runtime?
 *       Might want to rename.
 * TODO: Turn this into a compile-time task; vs runtime.
 */ 
int PWManager::initCharRanges()
{
  // Seed time and fill in map of char_range
  srand(time(NULL));
  map<unsigned, char_range_vector> *map = &this->char_set_map_;

  char_range_vector symbols_vec;
  char_range_vector numbers_vec;
  char_range_vector lower_vec;
  char_range_vector upper_vec;

  symbols_vec.push_back(symbols_range1);
  symbols_vec.push_back(symbols_range2);
  symbols_vec.push_back(symbols_range3);
  symbols_vec.push_back(symbols_range4);
  numbers_vec.push_back(numbers_range);
  lower_vec.push_back(lower_range);
  upper_vec.push_back(upper_range);
  
  map->emplace(SYMBOLS, symbols_vec);
  map->emplace(NUMBERS, numbers_vec);
  map->emplace(LOWER, lower_vec);
  map->emplace(UPPER, upper_vec);

  return 1;
}

/* PURPOSE: Returns random character based on enabled character_sets.
 * OUTPUT: Randomly generated char.
 * NOTE: char_range is a pair of ints; represents a series of ASCII chars.
 *       char_set is a vector of char_ranges.
 * LOGIC: ultimately, three random rolls are required to obtain a random char.
 * TODO: Is reusing a single rand() inappropriate? Possibly ruining distribution?
 * TODO: Determine if any helpers are needed; seems simple enough and under 40 
 *       lines.
 */
char PWManager::randChar()
{
  int rand_index1, rand_index2, rand_index3; 
  int rand_char;
  // Receive vector of possible char_sets.
  std::vector<unsigned> options = this->optionsToRoll();

  // Roll random char_set index.
  rand_index1 = rand() * options.size(); // rand value on [0, options.size)

  // Given a vector of char_ranges, Pick a random char_range.
  char_range_vector pairs_list = this->char_set_map_[rand_index1];
  rand_index2 = rand() * pairs_list.size(); 
  char_range rand_char_range = pairs_list[rand_index2];

  // roll random number on that char_range: [first, second)
  int distance = rand_char_range.second - rand_char_range.first;
  rand_char = rand_char_range.first + rand() * distance;
  
  return rand_char;  
}

bool PWManager::symbols() { return this->symbols_;}
bool PWManager::numbers() { return this->numbers_;}
bool PWManager::lower() { return this->lower_;}
bool PWManager::upper() { return this->upper_;}
unsigned PWManager::length() { return this->length_;}

