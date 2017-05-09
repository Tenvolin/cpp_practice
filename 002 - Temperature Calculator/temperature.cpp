#include <iostream>
double fToC(double farenheit);
double cToF(double celsius);

int main()
{
  int mode = 0; // 0: C to F; 1: F to C;
  double measure = 0; // take user input of temperature measure

  // !!! include handling kelvin
  std::cout << "Select conversion method:\n"
            << "0: Celsius to Farenheit\n"
            << "1: Farenheit to Celsius\n";
  std::cin >> mode;

  // !!! include error handling
  std::cout << "Please enter a number to convert:"; 
  std::cin >> measure;

  if (mode == 0) {
    std::cout << "output: " << cToF(measure);
  } else if (mode == 1) {
    std::cout << "output: " << fToC(measure);
  } else {
    std::cout << "You did not give a proper conversion option.\n";
  }
  
}

// Purpose: Convert from Farenheit to Celsius.
double fToC(double farenheit) {
  return (farenheit - 32) * 5/9;
}

double cToF(double celsius) {
  return (celsius * 9/5) + 32;
}