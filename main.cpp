#include "Decode.h"
#include "Encode.h"
#include <iostream>
#include <string>
using namespace std;
int main() {

  bool isRunning = true;
  
  int input;
  string plainText;
  string key;
  cout << "Welcome to my Vigenère cipher Program!" << endl;
  cout << "Please Select Either Option 1 or 2:" << endl;
  cout << " 1. Encode Text." << endl;
  cout << " 2. Decode Text." << endl;
  cout << " 3. Exit." << endl;
  cout << "Enter 1, 2, or 3: ";
  cin >> input;

  if (input == 1) {
    cout << "Please enter the text you wish to encode: ";
    getline(cin >> ws, plainText);
    cout << endl;
    cout << "Please enter the key you wish to use to encode your text: ";
    cin >> key;
    cout << endl;
    cout << "Plain Text: " << plainText << endl;
    cout << endl;
    cout << "Key: " << key << endl;
    cout << endl;

    Encode str(key, plainText);
    cout << "Encoded Text: " << str.encodeString();
    cout << endl;

  } else if (input == 2) {
    cout << "Please enter the text you wish to decode: ";
    getline(cin >> ws, plainText);
    cout << endl;
    cout << "Please enter the key you wish to use to dencode your text: ";
    cin >> key;
    cout << endl;
    cout << "Encoded Text: " << plainText << endl;
    cout << "Key: " << key << endl;
    Decode str1(key, plainText);
    cout << endl;
    cout << "Decoded Text: " << str1.dencodeString();
    cout << endl;
  } else if (input == 3) {
    isRunning = false;
    return 0;
  } else {
    cout << "Invalid input!" << endl;
  }
  
  cout << endl;
  cout << "Exited" << endl;
  return 0;
}