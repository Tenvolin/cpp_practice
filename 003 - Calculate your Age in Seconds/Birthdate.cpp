#include "Birthdate.h"
#include <ctime>
#include <iostream>
#include "Date.h"

// purpose: constructor that sets the birth date of current object.
// input: integers of day, month and year.
// output: nothing
Birthdate::Birthdate(int day, int month, int year)
{
  this->day_ = day;
  this->month_ = month;
  this->year_ = year;
}

// purpose: Considers current Birthdate and returns age in seconds.
//          Subtract current year from birth year; add with:
//          current month and current day, from birth day and year.
// input:   Nothing.
// output:  Number of seconds of age.
long long Birthdate::giveAgeInSeconds()
{
  int days_in_current_year = 0;      // # days elapsed in current year
  int days_prior_to_current_year = 0; // # days elapsed leading up to current year.
  const int days_in_leapyear = 366;
  const int days_In_Year = 365;
  const long long factor_days_to_seconds = 24 * 60 * 60; 

  long long days_elapsed_in_Life = 0;
  long long seconds_elapsed_in_life = 0;

  // give days passed in current year. range: [1, this->month_)
  for (int i = 1; i < this->month_; i++)
  {
    days_in_current_year = this->daysInMonth(i, this->year_);
  }
  days_in_current_year += this->day_;

  // give sum of days for each year before current year.
  for (int year = this->year_; year < CURRENT_YEAR; year++)
  {
    if (this->isLeapYear(year))
      days_prior_to_current_year += days_in_leapyear;
    else
      days_prior_to_current_year += days_In_Year;
  }

  days_elapsed_in_Life = days_in_current_year + days_prior_to_current_year;
  seconds_elapsed_in_life = days_elapsed_in_Life * factor_days_to_seconds;

  return seconds_elapsed_in_life;
}

// purpose: Determine if current year is a leap year.
// input:
// note:  Since returning false by default, consider only conditions
//          that must return true.
bool Birthdate::isLeapYear(int year)
{
  bool is_leap_year = false;

  if (year % 4 == 0 && year % 100 != 0 ||
      year % 400 == 0)
  {
    is_leap_year = true;
  }

  return is_leap_year;
}

// purpose: Returns true if number of days is valid within current month.
//           Considers leap years.
// input: Birthdate object.
// output: boolean.
bool Birthdate::isValidDay()
{
  int current_day = this->day_;
  int current_month = this->month_;
  int current_year = this->year_;
  int is_valid = false;
  int days_in_month = 0;

  days_in_month = this->daysInMonth(current_month, current_year);

  // 0 <= x <= days_in_month
  is_valid = current_day >= 0 && current_day <= days_in_month;

  return is_valid;
}

// purpose: Return number of days in a month, taking into account leap year status.
// input: number of months and current year
// output: total number of days in month; -1 if invalid month given.
int Birthdate::daysInMonth(int month, int year)
{
  int days_in_month = -1;
  int current_month = month;
  int currYear = year;

  // check if bday->day exists on allowed dates per month; e.g. [0, 31] or [0, 30]
  //    Consider February Leap years.
  if (current_month == 1 || current_month == 3 || current_month == 5 || current_month == 7 ||
      current_month == 8 || current_month == 10 || current_month == 12)
  {
    days_in_month = 31;
  }
  else if (current_month == 4 || current_month == 6 || current_month == 9 || current_month == 11)
  {
    days_in_month = 30;
  }
  else if (current_month == 2)
  {
    if (isLeapYear(year))
      days_in_month = 29;
    else
      days_in_month = 28;
  }
  else
  {
    // error: invalid month given
    days_in_month = -1;
  }

  return days_in_month;
}
