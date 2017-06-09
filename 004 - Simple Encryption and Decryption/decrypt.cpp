class MyDecrypter
{
public:
  static void decryptString(std::string &input, char encryptKey);
};

void MyDecrypter::decryptString(std::string &input, char encryptKey)
{
  for (int i = 0; i < input.size(); ++i) {
    input[i] = input[i] ^ encryptKey;
  }
}