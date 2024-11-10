#include <iostream>
using namespace std;

int main() {
  int a, b;
  while (cin >> a >> b) {
    cout << a << " " << b << " ";
    int Max = 0;
    for (int i = min(a, b); i <= max(a, b); i++) {
      int j = i;
      int len = 1;
      while (j != 1) {
        if (j & 1)
          j = j * 3 + 1;
        else
          j /= 2;
        len++;
      }
      Max = max(Max, len);
    }
    cout << Max << endl;
  }
  return 0;
}
