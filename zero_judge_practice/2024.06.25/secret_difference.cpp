#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string number;
  cin >> number;
  int odd = 0, even = 0;

  for (int i = 0; i < number.size(); i++) {
    if (i % 2 != 0)
      odd += int(number[i] - '0');
    else
      even += int(number[i] - '0');
  }
  cout << abs(odd - even);
  return 0;
}
