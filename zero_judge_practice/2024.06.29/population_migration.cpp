#include <climits>
#include <iostream>

using namespace std;

int R, C, k, m;
int people_of_each_city[50][50];
int receive[50][50];

int cities_nearby(int a, int b) {
  int count = 0;
  if (a - 1 != -1 && people_of_each_city[a - 1][b] != -1)
    count++;
  if (b + 1 != C && people_of_each_city[a][b + 1] != -1)
    count++;
  if (a + 1 != R && people_of_each_city[a + 1][b] != -1)
    count++;
  if (b - 1 != -1 && people_of_each_city[a][b - 1] != -1)
    count++;
  return count;
}

void receive_people_from_others(int n, int a, int b) {
  if (a - 1 != -1 && people_of_each_city[a - 1][b] != -1)
    receive[a - 1][b] += n;
  if (b + 1 != C && people_of_each_city[a][b + 1] != -1)
    receive[a][b + 1] += n;
  if (a + 1 != R && people_of_each_city[a + 1][b] != -1)
    receive[a + 1][b] += n;
  if (b - 1 != -1 && people_of_each_city[a][b - 1] != -1)
    receive[a][b - 1] += n;
}

// 7 4 -1
// 6 -1 2
//
// 7 5 -1
// 6 -1 2
void remaining_people_in_the_city(int a, int b) {
  if (people_of_each_city[a][b] != -1) {
    receive_people_from_others(people_of_each_city[a][b] / k, a, b);
    people_of_each_city[a][b] -=
        int(people_of_each_city[a][b] / k) * cities_nearby(a, b);
  }
}

int main() {
  cin >> R >> C >> k >> m;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      cin >> people_of_each_city[i][j];

  int Max = INT_MIN, Min = INT_MAX;

  while (m--) {

    for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++)
        remaining_people_in_the_city(i, j);

    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        people_of_each_city[i][j] += receive[i][j];
        receive[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      // cout << people_of_each_city[i][j] << " ";
      Max = max(Max, people_of_each_city[i][j]);
      if (people_of_each_city[i][j] < 0)
        continue;
      Min = min(Min, people_of_each_city[i][j]);
    }
    // cout << endl;
  }

  cout << Min << endl << Max;
  return 0;
}
