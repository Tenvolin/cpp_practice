#include <cstdlib>
#include <iostream>
#include <string>
#include "PWManager.h"
// TODO: Create rolling function.
// TODO: Create UI for changing settings and choosing to roll for password.
// TODO: Create functions to change settings.
// TODO: Create function to display current settings.
//

int main()
{
  int user_option = 0;
  printf("Welcome to password generator!\n");
  do {
    printf("Please Enter a number:");
    getUserInput(user_option);

    printf(
        "State:\n"
        "\t symbols\n"
        "\t numbers\n"
        "\t lowercase\n"
        "\t uppercase\n"
        "\t pw_length\n\n");

    printf(
        "1: Change settings.",
        "2: "
        "\n" );

  } while (user_option > 5);
  
}