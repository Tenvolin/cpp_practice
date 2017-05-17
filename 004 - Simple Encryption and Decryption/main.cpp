#include <iostream>
#include <string>
#include "encrypt.cpp"
#include "decrypt.cpp"


// purpose: receive user input, and XOR encrypt it!
int main()
{
  char user_key_char = '\0';
  std::string user_data = "";
  std::string user_key = "";

  // ask user string
  std::cout << "Please enter something to encrypt!: ";
  std::getline(std::cin, user_data); // let's use getline(), reliable userinput

  // ask for user input
  while (user_key.size() != 1) {
    std::cout << "Please enter a single key to encrypt with: ";
    std::getline(std::cin, user_key);
  }
  user_key_char = user_key[0];
  
  // encrypt
  MyEncrypter::encryptString(user_data, user_key_char);
  std::cout << "Encrypted form: " << user_data << std::endl;
  // decrypt
  MyDecrypter::decryptString(user_data, user_key_char);
  std::cout << "Decoded to: " << user_data << std::endl;
}