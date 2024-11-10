#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    bool first[7];
    bool second[7];
    for (int i = 0; i < 7; i++) {
      cin >> first[i];
    }
    for (int i = 0; i < 7; i++) {
      cin >> second[i];
    }
    bool tmp = 0;
    if (first[1] == first[3] || first[1] != first[5] ||
        second[1] == second[3] || second[1] != second[5]) {
      cout << "A";
      tmp = 1;
    }
    if (first[6] == 0 || second[6] == 1) {
      cout << "B";
      tmp = 1;
    }
    if (first[1] == second[1] || first[3] == second[3] ||
        first[5] == second[5]) {
      cout << "C";
      tmp = 1;
    }
    if (!tmp)
      cout << "None";
    cout << endl;
  }
  // 0123456
  // 1234567
  return 0;
}
