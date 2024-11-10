#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> array;
  vector<int> queries;
  for (int i = 1; i <= N; i++) {
    cin >> array[i];
  }
  for (int i = 1; i <= Q; i++) {
    cin >> queries[i];
  }

  return 0;
}
