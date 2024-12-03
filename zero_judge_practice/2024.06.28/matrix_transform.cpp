#include <iostream>
#include <vector>
using namespace std;

int arr[11][11];
int R, C, M;

void flip() {
  for (int i = 0; i < R / 2; i++)
    for (int j = 0; j < C; j++)
      swap(arr[i][j], arr[R - i - 1][j]);
}
// R = 3, C = 2;
// arr[0][0] arr[1][0]
// arr[0][1] arr[1][1]
//

void turn() {
  int tmp[11][11];
  int k = 0, l = 0;

  for (int i = 0; i < C; i++) {
    for (int j = 0; j < R; j++) {
      tmp[i][j] = arr[j][C - i - 1];
    }
  }
  swap(R, C);
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      arr[i][j] = tmp[i][j];
}
//  1 2
//  3 4
//  5 6
//  7 8
//
//  2 4 6 8
//  1 3 5 7
// tmp   arr
//(i, j) (j, C-i-1)
//(1, 2) (2, 0)

int main() {

  while (cin >> R >> C >> M) {

    for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++)
        cin >> arr[i][j];

    vector<int> manipulate(M);

    for (int mk = 0; mk < M; mk++) {
      cin >> manipulate[mk];
    }

    for (int mk = M - 1; mk >= 0; mk--) {
      if (manipulate[mk])
        flip();
      else
        turn();
    }

    cout << R << " " << C << endl;

    bool first = 1;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (!first)
          cout << " ";
        cout << arr[i][j];
        first = 0;
      }
      first = 1;
      cout << endl;
    }
  }

  return 0;
}
