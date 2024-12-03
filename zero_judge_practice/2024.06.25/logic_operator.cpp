#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  a = a != 0 ? 1 : 0;
  b = b != 0 ? 1 : 0;
  bool tmp = false;

  if ((a & b) == c) {
    tmp = true;
    cout << "AND\n";
  }
  if ((a | b) == c) {
    tmp = true;
    cout << "OR\n";
  }
  if ((a ^ b) == c) {
    tmp = true;
    cout << "XOR\n";
  }

  if (!tmp)
    cout << "IMPOSSIBLE\n";

  return 0;
}
