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

// After rolling for a char_set, dig into map to roll again to determine 
// ascii char.
const map<unsigned, char_range_vector > MAP_OF_CHAR_SETS;


// placeholder ranges for now
const std::pair<unsigned, unsigned> symbols_range1(1,1);
const std::pair<unsigned, unsigned> symbols_range2(1,1);
const std::pair<unsigned, unsigned> symbols_range3(1,1);
const std::pair<unsigned, unsigned> numbers_range(1, 1);
const std::pair<unsigned, unsigned> lower_range(1, 1);
const std::pair<unsigned, unsigned> upper_range(1, 1);

class PWManager
{
private:
  // Settings to toggle.
  bool symbols_;
  bool numbers_;
  bool lower_;
  bool upper_;
  unsigned length_;
  // functions
  std::vector<unsigned> OptionsToRoll();

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