#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  map<char, int> quantity, amount;
  for (int i = 0; i < S.size(); i++) {
    quantity[toupper(S[i])] += int(T[i] - '0');
    amount[toupper(S[i])]++;
  }

  map<char, vector<int>> ans;
  for (auto item : quantity) {
    int aver = item.second / amount[item.first];
    int left = item.second % amount[item.first];
    for (int i = 0; i < amount[item.first]; i++) {
      int tmp = aver;
      if (i + left >= amount[item.first])
        tmp++;
      ans[item.first].push_back(tmp);
    }
    reverse(ans[item.first].begin(), ans[item.first].end());
  }

  for (int i = 0; i < S.size(); i++) {
    cout << ans[toupper(S[i])][int(ans[toupper(S[i])].size()) - 1];
    ans[toupper(S[i])].pop_back();
  }

  return 0;
}
