#include <cstdlib>
#include <iostream>
#include <string>
#include "PWManager.h"
// TODO: Create rolling function and test.
// TODO: Create UI for changing settings and choosing to roll for password.
// TODO: Create functions to change settings.
// TODO: Create function to display current settings.
// TODO: Implement testing with stest header.
int main()
{
  int user_option = 0;
  PWManager pw_manager;

  printf("Welcome to password generator!\n");
  do {
    printf("Please Enter a number:");
    getUserInput(user_option);

    printf(
        "State: \n"
        "\t symbols: %d\n"
        "\t numbers: %d\n"
        "\t lowercase: %d\n"
        "\t uppercase: %d\n"
        "\t pw_length: %d\n"
        "===================\n",
        pw_manager.symbols(),
        pw_manager.numbers(),
        pw_manager.lower(),
        pw_manager.upper(),
        pw_manager.length() );

    printf(
        "1: Change settings.",
        "2: generate password"
        "\n" );
    
    

  } while (user_option < 0 || user_option > 5);
  
}