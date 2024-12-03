#include <climits>
#include <iostream>
using namespace std;

struct coord {
  int x, y;
};

int main() {
  int n;
  cin >> n;
  coord arr[n];
  int max = 0;
  int min = INT_MAX;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].x >> arr[i].y;
  }
  for (int i = 0; i < n - 1; i++) {
    int tmp = abs(arr[i].x - arr[i + 1].x) + abs(arr[i].y - arr[i + 1].y);
    if (tmp >= max)
      max = tmp;
    if (tmp <= min)
      min = tmp;
  }
  cout << max << " " << min;
  return 0;
}
