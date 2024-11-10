#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() {
  int numbers[3];
  priority_queue<int> ans;
  map<int, int> Map;

  for (int i = 0; i < 3; i++) {
    cin >> numbers[i];
    Map[numbers[i]]++;
  }

  int Max = 0;

  for (auto entry : Map) {
    if (entry.second >= Max) {
      Max = entry.second;
    }
    ans.push(entry.first);
  }
  cout << Max << " ";
  while (!ans.empty()) {
    cout << ans.top() << " ";
    ans.pop();
  }
  return 0;
}
