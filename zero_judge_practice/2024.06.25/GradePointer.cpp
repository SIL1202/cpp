#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

void passing(vector<int> a) {
  bool best_case = true;
  int max = 0;
  for (size_t i = 0; i < a.size(); i++) {
    if (a[i] < 60) {
      best_case = false;
      if (a[i] > max)
        max = a[i];
    }
  }
  if (best_case)
    cout << "best case\n";
  else
    cout << max << endl;
}

void failing(vector<int> a) {
  bool worst_cese = true;
  int min = 100;
  for (size_t i = 0; i < a.size(); i++) {
    if (a[i] >= 60) {
      worst_cese = false;
      if (a[i] < min) {
        min = a[i];
      }
    }
  }
  if (worst_cese)
    cout << "worst case\n";
  else
    cout << min << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> grade;
  while (n--) {
    int x;
    cin >> x;
    grade.push_back(x);
  }

  sort(grade.begin(), grade.end());

  for (size_t i = 0; i < grade.size(); i++) {
    cout << grade[i];
    if (i < grade.size() - 1)
      cout << " ";
  }
  cout << endl;
  passing(grade);
  failing(grade);
  return 0;
}
