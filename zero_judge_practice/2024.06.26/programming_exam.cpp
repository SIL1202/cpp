#include <climits>
#include <iostream>
#include <map>
using namespace std;

int main() {
  int n, t, s;
  int serious = 0;
  int Max = INT_MIN;
  cin >> n;
  map<int, int> record;
  for (int i = 0; i < n; i++) {
    cin >> t >> s;
    record[t] = s;
    if (s == -1)
      serious++;
    Max = max(Max, s);
  }
  int total = Max - n - serious * 2;
  if (total < 0)
    total = 0;
  cout << total << " ";
  for (auto &s : record) {
    if (s.second == Max) {
      cout << s.first;
      break;
    }
  }

  return 0;
}
