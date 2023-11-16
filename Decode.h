#include <cstring>
#include <string>
using namespace std;
class Decode {
public:
  string key;
  string encodedText;
  string decodedText;
  Decode(string x, string y) {
    key = x;
    encodedText = y;
  }

private:
  char getLetterLowerCase(char key_char, char plain_char) {
    int x = plain_char - key_char;
    char alpha[26];
    for (int i = 97; i <= 122; i++) {
      char tmp = i;
      alpha[i - 97] = tmp;
    }
    if (x < 0) {
      x += 26;
      return alpha[x];
    }
    return alpha[x];
  }

  char getLetterUpperCase(char key_char, char plain_char) {

    int x = plain_char - key_char;
    int j = 0;
    char alpha[26];
    for (int i = 65; i <= 90; i++) {
      char tmp = i;
      alpha[j] = tmp;
      j++;
    }
    if (x < 0) {
      x += 26;
      return alpha[x];
    }
    return alpha[x];
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
  string dencodeString() {
    int key_length = key.length();
    char *KEY_ARRAY = new char[key_length + 1];
    strcpy(KEY_ARRAY, key.c_str());

    int plainText_length = encodedText.length();
    char *PLAINTEXT_ARRAY = new char[plainText_length + 1];
    strcpy(PLAINTEXT_ARRAY, encodedText.c_str());
    string encode = "";
    int x = 0;

    for (int i = 0; i < plainText_length; i++) {
      int tmp = PLAINTEXT_ARRAY[i];
      if (PLAINTEXT_ARRAY[i] == ' ') {
        encode += " ";
        continue;
      }
      // encode += bridge(KEY_ARRAY[x], PLAINTEXT_ARRAY[i]);
      // x++;
      // if (x >= key_length) {
      //   x = 0;
      // }
      // tmp < 65 || tmp > 90
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
        x++; // problem line
        if (x >= key_length) {
          x = 0;
        }
      }
    }
    return encode;
  }
};