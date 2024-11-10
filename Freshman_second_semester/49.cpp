#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int num;
  bool isPrime, isEmirp;

  while (cin >> num) {
    isPrime = true;
    isEmirp = true;

    // Determine if num is a prime number
    for (int i = 2; i <= sqrt(num); i++) {
      if (num % i == 0) {
        isPrime = false;
        break;
      }
    }

    if (isPrime) {
      // reverse the num and determine if reverse_num is a prime
      string tmp = to_string(num);

      int reverse_num = 0;
      for (int i = tmp.length() - 1; i >= 0; i--) {
        reverse_num = reverse_num * 10 + (tmp[i] - '0');
      }
      if (num == reverse_num) {
        isEmirp = false;
      } else {
        for (int i = 2; i <= sqrt(reverse_num); i++) {
          if (reverse_num % i == 0) {
            isEmirp = false;
            break;
          }
        }
      }

      if (isEmirp) {
        cout << num << " is emirp." << endl;
      } else {
        cout << num << " is prime." << endl;
      }
    } else {
      cout << num << " is not prime." << endl;
    }
  }
  return 0;
}
