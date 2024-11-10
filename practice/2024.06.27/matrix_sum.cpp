#include <iostream>
using namespace std;

int M[55][55];
int X[55 * 55], Y[55 * 55];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> M[i][j];

  int num = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int sum = 0;
      for (int x = max(0, i - M[i][j]); x < min(n, i + M[i][j] + 1); x++) {
        for (int y = max(0, j - M[i][j]); y < min(m, j + M[i][j] + 1); y++) {
          if (abs(x - i) + abs(y - j) <= M[i][j])
            sum += M[x][y];
        }
      }
      sum %= 10;
      if (sum == M[i][j])
        X[num] = i, Y[num] = j, num++;
    }
  }

  cout << num << endl;
  for (int i = 0; i < num; i++)
    cout << X[i] << " " << Y[i] << endl;

  return 0;
}
