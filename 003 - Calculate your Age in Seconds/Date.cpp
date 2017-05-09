#include "Date.h"
#include <ctime>
#include <iostream>

// purpose: constructor that sets the birth date of current object.
// input: integers of day, month and year.
// output: nothing
Birthday::Birthday(int day, int month, int year)
{
  this->day_ = day;
  this->month_ = month;
  this->year_ = year;
}

// purpose: Considers current birthday and returns age in seconds.
//          Subtract current year from birth year; add with:
//          current month and current day, from birth day and year.
// input:   Nothing.
// output:  Number of seconds of age.
long long int Birthday::giveAgeInSeconds()
{
  int daysInCurrentYear = 0;      // # days elapsed in current year
  int daysPriorToCurrentYear = 0; // # days elapsed leading up to current year.
  int daysInLeapyear = 366;
  int daysInYear = 365;
  long long int factorDaysToSeconds = 24 * 60 * 60; // days * 24hrs/day * 60mins/hr * 60s/min

  // give days passed in current year. range: [1, this->month_)
  for (int i = 1; i < this->month_; i++)
  {
    daysInCurrentYear = this->daysInMonth(i, this->year_);
  }
  daysInCurrentYear += this->day_;

  // give sum of days for each year before current year.
  for (int year = this->year_; year < CURRENT_YEAR; year++)
  {
    // if leapyear, 366 days; else 355 days
    if (this->isLeapYear(year))
      daysPriorToCurrentYear += daysInLeapyear;
    else
      daysPriorToCurrentYear += daysInYear;
  }
  
  long long int daysElapsedInLife = 0;
  long long int secondsElapsedInLife = 0;
  daysElapsedInLife = daysInCurrentYear + daysPriorToCurrentYear;

  secondsElapsedInLife = daysElapsedInLife * factorDaysToSeconds;

  return secondsElapsedInLife;
}

// purpose: Determine if current year is a leap year.
// input:
// note:  Since returning false by default, consider only conditions
//          that must return true.
bool Birthday::isLeapYear(int year)
{
  bool isLeapYear = false;

  if (year % 4 == 0 && year % 100 != 0 ||
      year % 400 == 0)
  {
    isLeapYear = true;
  }

  return isLeapYear;
}

// purpose: Returns true if number of days is valid within current month.
//           Considers leap years.
// input: Birthday object.
// output: boolean.
bool Birthday::isValidDay()
{
  int currDay = this->day_;
  int currMonth = this->month_;
  int currYear = this->year_;
  int isValid = false;
  int allotedDaysInMonth = 0;

  allotedDaysInMonth = this->daysInMonth(currMonth, currYear);

  // 0 <= x <= AllotedDaysInMonth
  isValid = currDay >= 0 && currDay <= allotedDaysInMonth;

  return isValid;
}

// purpose: Return number of days in a month, taking into account leap year status.
// input: number of months and current year
// output: total number of days in month; -1 if invalid month given.
int Birthday::daysInMonth(int month, int year)
{
  int daysInMonth = -1;
  int currMonth = month;
  int currYear = year;

  // check if bday->day exists on allowed dates per month; e.g. [0, 31] or [0, 30]
  //    Consider February Leap years.
  if (currMonth == 1 || currMonth == 3 || currMonth == 5 || currMonth == 7 ||
      currMonth == 8 || currMonth == 10 || currMonth == 12)
  {
    daysInMonth = 31;
  }
  else if (currMonth == 4 || currMonth == 6 || currMonth == 9 || currMonth == 11)
  {
    daysInMonth = 30;
  }
  else if (currMonth == 2)
  {
    if (isLeapYear(year))
      daysInMonth = 29;
    else
      daysInMonth = 28;
  }
  else
  {
    // error: invalid month given
    daysInMonth = -1;
  }

  return daysInMonth;
}
