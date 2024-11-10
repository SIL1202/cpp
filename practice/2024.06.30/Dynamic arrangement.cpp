#include <climits>
#include <iostream>
#include <string>
using namespace std;

string arr[100];
int m, n, h;

void add_line(int a, int b) {
  for (int i = a - 1; i >= 0; i--) { // up
    if (arr[i][b] == '@') {
      for (int j = a - 1; j > i; j--) {
        if (arr[j][b] == '-')
          arr[j][b] = '+';
        if (arr[j][b] == '_')
          arr[j][b] = '|';
      }
      break;
    }
  }

  for (int i = a + 1; i < m; i++) { // down
    if (arr[i][b] == '@') {
      for (int j = a + 1; j < i; j++) {
        if (arr[j][b] == '-')
          arr[j][b] = '+';
        if (arr[j][b] == '_')
          arr[j][b] = '|';
      }
      break;
    }
  }

  for (int i = b + 1; i < n; i++) { // right
    if (arr[a][i] == '@') {
      for (int j = b + 1; j < i; j++) {
        if (arr[a][j] == '|')
          arr[a][j] = '+';
        if (arr[a][j] == '_')
          arr[a][j] = '-';
      }
      break;
    }
  }

  for (int i = b - 1; i >= 0; i--) { // left
    if (arr[a][i] == '@') {
      for (int j = b - 1; j > i; j--) {
        if (arr[a][j] == '|')
          arr[a][j] = '+';
        if (arr[a][j] == '_')
          arr[a][j] = '-';
      }
      break;
    }
  }
}

void remove_line(int a, int b) {
  for (int i = a - 1; i >= 0; i--) {
    if (arr[i][b] == '@') {
      for (int j = a - 1; j > i; j--) {
        if (arr[j][b] == '|')
          arr[j][b] = '_';
        if (arr[j][b] == '+')
          arr[j][b] = '-';
      }
      break;
    }
  }

  for (int i = a + 1; i < m; i++) {
    if (arr[i][b] == '@') {
      for (int j = a + 1; j < i; j++) {
        if (arr[j][b] == '|')
          arr[j][b] = '_';
        if (arr[j][b] == '+')
          arr[j][b] = '-';
      }
      break;
    }
  }

  for (int i = b + 1; i < n; i++) {
    if (arr[a][i] == '@') {
      for (int j = b + 1; j < i; j++) {
        if (arr[a][j] == '-') {
          arr[a][j] = '_';
        }
        if (arr[a][j] == '+') {
          arr[a][j] = '|';
        }
      }
      break;
    }
  }

  for (int i = b - 1; i >= 0; i--) {
    if (arr[a][i] == '@') {
      for (int j = b - 1; j > i; j--) {
        if (arr[a][j] == '-') {
          arr[a][j] = '_';
        }
        if (arr[a][j] == '+') {
          arr[a][j] = '|';
        }
      }
      break;
    }
  }
}

void add(int a, int b) {
  arr[a][b] = '@';
  add_line(a, b);
}

void remove(int a, int b) {
  arr[a][b] = '_';
  remove_line(a, b);
}

int main() {
  cin >> m >> n >> h;
  // 初始化陣列
  for (int i = 0; i < m; i++) {
    arr[i] = string(n, '_');
  }

  int ans;
  int Max = INT_MIN;
  for (int i = 0; i < h; i++) {
    int r, c, t;
    cin >> r >> c >> t;

    if (t == 0) {
      add(r, c);
    } else if (t == 1) {
      remove(r, c);
    }
    int count = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (arr[i][j] == '@' || arr[i][j] == '|' || arr[i][j] == '-' ||
            arr[i][j] == '+')
          count++;
      }
    }

    ans = count;
    Max = max(Max, count);
  }

  // 輸出陣列
  /*
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++)
        cout << arr[i][j] << " ";
      cout << endl;
    }
    */

  cout << Max << endl << ans;
  return 0;
}
/*
@ _ _ _ _
_ _ _ @ _
_ _ _ _ _
_ _ _ _ _
@ _ _ @ _

5 5 4
0 0 0
1 3 0
4 0 0
4 3 0
*/
