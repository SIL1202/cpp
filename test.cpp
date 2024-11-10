#include <iostream>
#include <vector>

using namespace std;

int digitsum(int n) {
  int result = 0;
  while (n > 0) {
    result += n % 10;
    n /= 10;
  }
  return result;
}
int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> digitsums(N + 1);
  vector<int> array(N + 1);
  vector<int> queries(Q + 1);
  for (int i = 1; i <= N; i++) {
    cin >> array[i];
    digitsums[i] = digitsum(array[i]); // digitsums.first is answer
  }

  for (int i = 1; i <= Q; i++) {
    cin >> queries[i];
  }

  for (int i = 1; i <= Q; i++) {
    int queryIndex = queries[i];
    bool found = false;
    for (int j = queryIndex + 1; j <= N; j++) {
      if (array[queryIndex] < array[j] &&
          digitsums[queryIndex] > digitsums[j]) {
        cout << j << endl;
        found = true;
        break;
      }
    }

    if (!found)
      cout << -1 << endl;
  }

  // 1  2  3  4  5
  // 62 70 28 62 92 . . . . . .
  // 8  7  10 8  11

  return 0;
}
