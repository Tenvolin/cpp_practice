#include <vector>

#ifndef PASSWORD_MANAGER
#define PASSWORD_MANAGER

const unsigned SYMBOLS = 0;
const unsigned NUMBERS = 1;
const unsigned LOWER = 2;
const unsigned UPPER = 3;
const unsigned PW_LENGTH = 16;

class PWManager
{
private:
  // Settings to toggle.
  bool symbols_;
  bool numbers_;
  bool lower_case_;
  bool upper_case_;

  unsigned pw_length_;

  std::vector<unsigned> OptionsToRoll();

public:
  int length(int length);

  PWManager();
  ~PWManager();
};

#endif // PASSWORD_MANAGER