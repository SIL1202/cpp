#include <iostream>
#include <map>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int i;
  cin >> i;
  int ans = 0;

  while (i--) {
    int n;

    map<int, int> Map;
    while (cin >> n && n != 0) {
      if (n > 0)
        Map[n]++;
      else
        Map[n * -1]--;
    }
    if (Map[a] > 0 && Map[b] > 0)
      ans++;
  }
  cout << ans;

  return 0;
}
