#include <iostream>
#include <string>
#include "encrypt.cpp"
#include "decrypt.cpp"

int main()
{
  std::string user_input;
  // let's use getline(), as it reliably feeds us a string.
  std::cout << "Please enter something to encrypt!" << std::endl;
  std::getline(std::cin, user_input);

  std::cout << user_input.size() << std::endl;

  std::cout << "Your input: " << user_input << std::endl;

  MyEncrypter::encryptString(user_input);
  std::cout << "Encrypted form: " << user_input << std::endl;

  MyDecrypter::decryptString(user_input);
  std::cout << "Decoded to: " << user_input << std::endl;
}