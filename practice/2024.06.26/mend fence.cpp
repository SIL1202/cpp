#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int h[n];
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  int ans = 0;
  if (h[0] == 0)
    ans += h[1];
  if (h[n - 1] == 0)
    ans += h[n - 2];

  for (int i = 1; i < n - 1; i++) {
    if (h[i] == 0) {
      ans += min(h[i - 1], h[i + 1]);
    }
  }

  cout << ans;
  return 0;
}
