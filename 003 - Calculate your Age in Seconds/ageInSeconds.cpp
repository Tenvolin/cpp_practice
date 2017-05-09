#include "Date.h"
#include <iostream>

int main()
{
  int day = 0, month = 0, year = 0;
  // grab user birthday. Ask user to input numbers representing the date in dd/mm/yyyy format
  std::cout << "Enter your birthday as three numbers and get your age in seconds!\n Enter in form of: dd/mm/yyyy" << std::endl;
  std::cin >> day >> month >> year;
  
  Birthday *birthday = new Birthday(day, month, year);

  long long int ageInSeconds = birthday->giveAgeInSeconds();
  std::cout << "age in seconds: " << ageInSeconds << std::endl;
  // guard each month against number of allowed days

  
  // Grab time from current day and calculate!

  // Birthday *birthday = new Birthday(29, 1, 1900);
  // int test = 0;
  // test = birthday->();
  // std::cout << test << std::endl;
}

// todo: create a header file for Date.cpp
// todo: Split up functions into another class if need by.
// todo: Have Birthday extend date, maybe.
// todo: Create a testing suite for all the individual helper functions.
// todo: Split up functions into a calendar header file --> all extraneous functions
// todo: redo isValidDay to take in current days
// todo: currently overflowing integer; why is long long int not sufficient?
// todo: add birth time of the day; // Assume everyone is born @ 00:00 hours.

// giveAgeInSeconds
// isLeapYear() -- good;
// daysInMonth() -- good;
// isValidDay() -- good;
