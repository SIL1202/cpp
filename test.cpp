#include <climits>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

long long MaxHeight(vector<long long> height) {
  int Max = INT_MIN;
  for (int i = 0; i < height.size(); i++) {
    if (Max < height[i])
      Max = height[i];
  }
  return Max;
}

stack<long long> reverse(stack<long long> st) {
  stack<long long> reverse_st;
  while (!st.empty()) {
    reverse_st.push(st.top());
    st.pop();
  }
  return reverse_st;
}

long long Stamina(stack<long long> st) {
  vector<long long> height;
  st = reverse(st);
  while (!st.empty()) {
    long long sta = 0;
    stack<long long> copySt(st);
    while (!copySt.empty()) {
      sta ^= copySt.top();
      copySt.pop();
    }
    // cout << "sta = " << sta << endl;
    height.push_back(sta);
    st.pop();
  }
  return MaxHeight(height);
}

int main() {
  int n;
  cin >> n;
  vector<long long> vec(n);
  stack<long long> st;
  vector<long long> comparison;
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    if (vec[i] <= vec[i - 1] && i != 0) {
      comparison.push_back(Stamina(st));
      while (!st.empty()) {
        st.pop();
      }
    }
    st.push(vec[i]);
    // cout << "vec[" << i << "] = " << vec[i] << endl;
  }
  cout << MaxHeight(comparison);
}
