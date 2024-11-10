#include <iostream>
using namespace std;

int main() {
  int n, x, y, pre_x, pre_y, dir, pre_dir = 0;
  int left = 0, right = 0, rev = 0;
  cin >> n >> pre_x >> pre_y;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    if (x > pre_x)
      dir = 0;
    else if (y < pre_y)
      dir = 1;
    else if (x < pre_x)
      dir = 2;
    else
      dir = 3;

    if (dir == (pre_dir + 1) % 4)
      right++;
    else if (dir == (pre_dir + 2) % 4)
      rev++;
    else if (dir == (pre_dir + 3) % 4)
      left++;
    // else no direction changed
    // current -> previous for next point
    pre_dir = dir;
    pre_x = x, pre_y = y;
  }
  cout << left << " " << right << " " << rev;
  return 0;
}
