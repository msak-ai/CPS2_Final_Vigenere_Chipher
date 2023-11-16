#include <cstring>
#include <string>
using namespace std;
class Encode {
public:
  string key;
  string plainText;

  Encode(string x, string y) {
    key = x;
    plainText = y;
  }

private:
  char getLetterLowerCase(char key_char, char plain_char) {
    // Give the position of the encode letter in the alphabet.
    int x = (key_char - 96) + (plain_char - 96) - 1;
    // Populates the alpha array with the lowercase letters in alphabet.
    char alpha[26];
    for (int i = 97; i <= 122; i++) {
      char tmp = i;
      alpha[i - 97] = tmp;
    }
    // Ensures that x is in the range of [0, 26] and returns encode char.
    if (x > 26) {
      return alpha[(x - 26)] - 1;
    }
    return alpha[x - 1];
  }

  char getLetterUpperCase(char key_char, char plain_char) {
    // Give the position of the encode letter in the alphabet.
    int x = (key_char - 64) + (plain_char - 64) - 1;
    // Populates the alpha array with the uppercase letters in alphabet.
    char alpha[26];
    for (int i = 65; i <= 90; i++) {
      char tmp = i;
      alpha[i - 65] = tmp;
    }
    // Ensures that x is in the range of [0, 26] and returns encode char.
    if (x > 26) {
      return alpha[(x - 26)] - 1;
    }
    return alpha[x - 1];
  }

  char bridge(char key_char, char plain_char) {
    // Checks to see if the plain_char is uppercase
    if (plain_char >= 65 && plain_char <= 90) {
      // If plain_char is uppercase and key_char is uppercase then
      // getLetterUpperCase is called
      if (key_char >= 65 && key_char <= 90) {
        return getLetterUpperCase(key_char, plain_char);
      }
      // If not then key_char is made an uppercase letter then
      // getLetterUpperCase is called
      else if (key_char >= 97 && key_char <= 122) {
        char tmp = toupper(key_char);
        return getLetterUpperCase(tmp, plain_char);
      }
    }
    // Checks to see if the plain_char is lowercase
    else if (plain_char >= 97 && plain_char <= 122) {
      // If plain_char is lowercase and key_char is lowercase then
      // getLetterLowerCase is called
      if (key_char >= 97 && key_char <= 122) {
        return getLetterLowerCase(key_char, plain_char);
      }
      // If not then key_char is made an lowercase letter then
      // getLetterLowerCase is called
      else if (key_char >= 65 && key_char <= 90) {
        char tmp = tolower(key_char);
        return getLetterLowerCase(tmp, plain_char);
      }
      // Returns any character that is not an empty space or lower or uppercase
      // letter.
    }
    return ' ';
  }

public:
  string encodeString() {
    int key_length = key.length();
    char *KEY_ARRAY = new char[key_length + 1];
    strcpy(KEY_ARRAY, key.c_str());

    int plainText_length = plainText.length();
    char *PLAINTEXT_ARRAY = new char[plainText_length + 1];
    strcpy(PLAINTEXT_ARRAY, plainText.c_str());
    string encode = "";
    int x = 0;

    for (int i = 0; i < plainText_length; i++) {
      int tmp = PLAINTEXT_ARRAY[i];
      if (PLAINTEXT_ARRAY[i] == ' ') {
        encode += " ";
        continue;
      }

      else if (tmp >= 33 && tmp <= 64) {
        encode += PLAINTEXT_ARRAY[i];
        continue;
      }

      else if (tmp >= 91 && tmp <= 96) {
        encode += PLAINTEXT_ARRAY[i];
        continue;
      }

      else if (tmp >= 123 && tmp <= 126) {
        encode += PLAINTEXT_ARRAY[i];
        continue;
      }

      else {

        encode += bridge(KEY_ARRAY[x], PLAINTEXT_ARRAY[i]);
        x++;
        if (x >= key_length) {
          x = 0;
        }
      }
    }
    return encode;
  }
};