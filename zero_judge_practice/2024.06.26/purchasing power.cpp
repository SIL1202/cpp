#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;

  int ans = 0;
  int count = 0;
  while (n--) {
    int aver = 0;
    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    int Max = max({d1, d2, d3});
    int Min = min({d1, d2, d3});
    aver = (d1 + d2 + d3) / 3;
    if (Max - Min >= d) {
      count++;
      ans += aver;
    }
  }
  cout << count << " " << ans;
  return 0;
}
