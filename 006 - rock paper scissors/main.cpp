#include <iostream>
#include <time.h>
#include <string>
#include <cstdio>
// purpose: determine if user or opponent wins.
// output: 0=lose; 1=win; 2=tie;
unsigned gameLogic(unsigned user, unsigned opponent)
{
  bool win_cond = false;
  bool is_tie = false;
  const unsigned rock = 0;
  const unsigned paper = 1;
  const unsigned scissors = 2;

  switch (user)
  {
    // each case has three lines: 
    //    line1= win; line2=loss; line3=tie.
  case rock: 
    (opponent == scissors) ? win_cond = true :
    (opponent == paper) ? win_cond = false :
    is_tie = true;
    break;
  case paper:
    (opponent == rock) ? win_cond = true :
    (opponent == scissors) ? win_cond = false :
    is_tie = true;
    break;
  case scissors:
    (opponent == paper) ? win_cond = true :
    (opponent == rock) ? win_cond = false :
    is_tie = true;
    break;
  default:
    std::cout << "Error, wrong inputs" << std::endl;
    break;
  }

  // win_cond matches 0 or 1 as loss/win respectively.
  if (is_tie)
    return 2;
  else
    return win_cond;
}

// purpose: prints to console the rock/paper/scissor choice.
// in: unsigned int
// pre: choice must be on [0,2]
std::string giveChoiceString(unsigned choice)
{
  std::string return_string = "";

  if (choice == 0)
    return_string = "rock";
  else if (choice == 1)
    return_string = "paper";
  else
    return_string = "scissors";

  return return_string;
}

int main()
{
  std::srand(time(0));
  unsigned user_choice;
  unsigned computer_choice;  
  std::string user_choice_str;
  unsigned result = 0;

  // generate computer choice;
  computer_choice = (std::rand() * RAND_MAX) % 3; // recall any multiple of 3 becomes 0!

  // request user choice 
  printf("Please enter your choice for rock paper and scissors:\n"
          "0: rock\n"
          "1: paper\n"
          "2: scissors\n");
  do {
    getline(std::cin, user_choice_str);
    user_choice = std::stoi(user_choice_str);
  } while(user_choice < 0 || user_choice > 2); // req: [0, 2]
  

  // play the game!
  result = gameLogic(user_choice, computer_choice);
  std::cout << "You chose " << giveChoiceString(user_choice) << std::endl;
  std::cout << "Your opponent chose " << giveChoiceString(computer_choice) << std::endl;
  
  // print the result.
  std::cout << result << std::endl;
  if (result == 0)
    std::cout << "You lost!" << std::endl;
  else if (result == 1)
    std::cout << "You won!" << std::endl;
  else
    std::cout << "It was a tie!" << std::endl;

  return 0;
}


