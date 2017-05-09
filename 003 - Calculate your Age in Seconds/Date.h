#ifndef CPP_003_DATE_H_

#define CPP_003_DATE_H_
const int CURRENT_YEAR = 2017;

class Birthday
{
private:
  int day_;
  int month_;
  int year_;

public:
  Birthday(int day, int month, int year);
  long long int giveAgeInSeconds();
  int daysInMonth(int month, int year);
  bool isValidDay();
  bool isLeapYear(int year);
};
#endif // CPP_003_DATE_H_