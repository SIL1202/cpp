#include <iostream>
#include <string>
#include <vector>
using namespace std;

string mora(int a, int b) {
  if (a == 0 && b == 0 || a == 2 && b == 2 || a == 5 && b == 5)
    return "Drew";
  else if (a == 0 && b == 2 || a == 2 && b == 5 || a == 5 && b == 0)
    return "Won";
  else
    return "Lost";
}

int main() {
  int F, N, bro, sis;
  cin >> F >> N;
  int round = 0;
  vector<int> Sis_vector, bro_vector;
  while (N--) {
    round++;
    cin >> sis;
    Sis_vector.push_back(sis);
    if (round == 1)
      bro_vector.push_back(F);
    if (round > 1) {
      if (round > 2 && Sis_vector[Sis_vector.size() - 2] ==
                           Sis_vector[Sis_vector.size() - 3]) {
        if (Sis_vector[Sis_vector.size() - 2] == 0)
          bro_vector.push_back(5);
        else if (Sis_vector[Sis_vector.size() - 2] == 2)
          bro_vector.push_back(0);
        else if (Sis_vector[Sis_vector.size() - 2] == 5)
          bro_vector.push_back(2);
      } else
        bro_vector.push_back(Sis_vector[Sis_vector.size() - 2]);
    }
    string ans = mora(bro_vector.back(), Sis_vector.back());
    if (ans != "Drew") {
      for (auto s : bro_vector) {
        cout << s << " ";
      }
      cout << ": " << mora(bro_vector.back(), Sis_vector.back()) << " at round "
           << round;
      return 0;
    }
  }
  for (auto s : bro_vector) {
    cout << s << " ";
  }
  cout << ": " << mora(bro_vector.back(), Sis_vector.back()) << " at round "
       << round;
  return 0;
}
