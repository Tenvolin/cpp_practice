#include <string>
#include <iostream>

class MyEncrypter
{
public:
  static void encryptString(std::string &input);
};

// purpose: encrypts a string
// in: out_input
void MyEncrypter::encryptString(std::string &input)
{
  for (int i = 0; i < input.size(); ++i)
  {
     input[i] = input[i] + 1;
  }
}