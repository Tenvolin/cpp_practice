#include <vector>
#include <map>

#ifndef PASSWORD_MANAGER
#define PASSWORD_MANAGER
using std::vector;
using std::pair;
using std::map;

typedef pair<unsigned, unsigned> char_range; // on [begin,end)
typedef vector<char_range> char_range_vector;

// Used to determine what char sets we're rolling for.
const unsigned SYMBOLS = 0;
const unsigned NUMBERS = 1;
const unsigned LOWER = 2;
const unsigned UPPER = 3;
const unsigned PW_LENGTH = 16;

// ASCII char ranges.
const char_range symbols_range1(33,48);
const char_range symbols_range2(58,65);
const char_range symbols_range3(91,97);
const char_range symbols_range4(123,127);
const char_range numbers_range(48,58);
const char_range lower_range(97,123);
const char_range upper_range(65,91);

class PWManager
{
private:
  // Settings to toggle.
  bool symbols_;
  bool numbers_;
  bool lower_;
  bool upper_;
  unsigned length_;
  // After rolling for a char_set, access map to roll again to determine ascii char
  map<unsigned, char_range_vector> char_set_map_;
  // functions
  vector<unsigned> optionsToRoll();
  int initCharRanges(); 
  char randChar();
  
  
public:
  int length(int length);
  bool symbols();
  bool numbers();
  bool lower();
  bool upper();
  unsigned length();

  PWManager();
  ~PWManager();
};

void getUserInput(int &user_option);
#endif // PASSWORD_MANAGER