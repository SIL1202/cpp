#include <iostream>
#include <string>
using namespace std;

int main() {
  string keyboard = "`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
  string getkey;
  while (getline(cin, getkey)) {
    for (auto i : getkey) {
      if (i == ' ')
        cout << i;
      else
        cout << keyboard[keyboard.find(tolower(i)) - 2];
    }
    cout << endl;
  }
  return 0;
}
