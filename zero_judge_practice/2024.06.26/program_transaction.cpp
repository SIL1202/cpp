#include <iostream>
using namespace std;

int main() {
  int n, D;
  cin >> n >> D;
  int ans = 0;
  int current = 0;
  int a[n + 1];
  bool hold = 1;
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
    current = a[1];
  }
  for (int i = 2; i < n + 1; i++) {
    if (a[i] >= (current + D) && hold == 1) { // sell
      ans += a[i] - current;
      current = a[i];
      hold = 0;
    }
    if (a[i] <= (current - D) && hold == 0) { // buy
      current = a[i];
      hold = 1;
    }
  }
  cout << ans;
  return 0;
}
