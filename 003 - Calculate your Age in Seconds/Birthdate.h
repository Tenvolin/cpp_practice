#include "Date.h"
class Birthdate : public Date
{
public:
  Birthdate(int day, int month, int year);
  long long giveAgeInSeconds();
  int daysInMonth(int month, int year);
  bool isValidDay();
  bool isLeapYear(int year);
};