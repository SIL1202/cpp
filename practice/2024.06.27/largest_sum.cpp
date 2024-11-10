#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int xi;

  vector<int> max_numbers;
  for (int i = 0; i < N; i++) {
    int Max = INT_MIN;
    for (int j = 0; j < M; j++) {
      cin >> xi;
      Max = max(Max, xi);
    }
    max_numbers.push_back(Max);
  }

  int S = 0;
  for (auto s : max_numbers) {
    S += s;
  }
  cout << S << endl;

  bool fail = true;

  for (auto s : max_numbers) {
    if (S % s == 0) {
      if (!fail)
        cout << " ";
      cout << s;
      fail = 0;
    }
  }
  if (fail) {
    cout << "-1";
  }
  cout << endl;

  return 0;
}
