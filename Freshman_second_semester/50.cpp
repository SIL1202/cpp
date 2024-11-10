#include <iostream>
using namespace std;

struct Array2D {
  char **data;
  int rows;
  int cols;
};
// ***
// *.*
// ***
int convert(Array2D arr, int n, int m) {
  int num = 0;
  if (n - 1 >= 0 && m - 1 >= 0 && arr.data[n - 1][m - 1] == '*')
    num++;
  if (n - 1 >= 0 && m >= 0 && arr.data[n - 1][m] == '*')
    num++;
  if (n - 1 >= 0 && m + 1 < arr.cols && arr.data[n - 1][m + 1] == '*')
    num++;
  if (n >= 0 && m - 1 >= 0 && arr.data[n][m - 1] == '*')
    num++;
  if (n >= 0 && m + 1 < arr.cols && arr.data[n][m + 1] == '*')
    num++;
  if (n + 1 < arr.rows && m - 1 >= 0 && arr.data[n + 1][m - 1] == '*')
    num++;
  if (n + 1 < arr.rows && arr.data[n + 1][m] == '*')
    num++;
  if (n + 1 < arr.rows && m + 1 < arr.cols && arr.data[n + 1][m + 1] == '*')
    num++;
  return num;
}

int main() {
  int n, m;
  int count = 0;
  while (cin >> n >> m) {
    if (n == 0 && m == 0)
      break;
    count++;
    Array2D field;
    field.rows = n;
    field.cols = m;
    field.data = new char *[n];

    for (int i = 0; i < n; i++) {
      field.data[i] = new char[m];
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> field.data[i][j];
      }
    }

    cout << "Field #" << count << ":\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (field.data[i][j] != '*')
          cout << convert(field, i, j);
        else
          cout << "*";
      }
      cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
      delete[] field.data[i];
    }
    delete[] field.data;
  }
  return 0;
}
