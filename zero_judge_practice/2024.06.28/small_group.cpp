#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int people[n];
  int dics[n];
  int count = 0;
  // cout << "0 1 2 3 4 5 6 7 8 9\n";
  for (int i = 0; i < n; i++) {
    cin >> people[i];
    dics[i] = i;
  }

  // cout << "----\n";
  for (int i = 0; i < n; i++) {
    int tmp = i;
    // cout << "dics[" << i << "] = " << dics[i] << endl;
    if (dics[tmp] == -1)
      continue;
    while (1) {
      int index = tmp;
      tmp = people[tmp];
      // cout << "tmp = " << tmp << endl;
      dics[index] = -1;
      if (people[tmp] == i) {
        index = tmp;
        tmp = people[tmp];
        dics[index] = -1;
        break;
      } // 0 1 2 3 4 5 6 7 8 9
        // 4 7 2 9 6 0 8 1 5 3

      // cout << "people[tmp] = " << people[tmp] << endl;
    }
    count++;
    // cout << "count = " << count << endl;
  }
  // cout << "----\n";
  cout << count;

  return 0;
}

// 10
// 0 1 2 3 4 5 6 7 8 9
// 4 7 2 9 6 0 8 1 5 3

// i == 0;
// tmp =
