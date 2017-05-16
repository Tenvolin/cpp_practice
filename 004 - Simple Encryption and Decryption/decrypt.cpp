class MyDecrypter
{
public:
  static void decryptString(std::string &input);
};

void MyDecrypter::decryptString(std::string &input)
{
  for (int i = 0; i < input.size(); ++i)
  {
    input[i] = input[i] - 1;
  }
}