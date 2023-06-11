#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    if(k == 1) {
      cout << n << "\n";
    } else if(n % k == 0) {
      cout << (n / k + 1) << "\n";
    }else if (n % k == 1) {
      cout << (n / k + 1) << "\n";
    } else {
      cout << (n / k + 2) << "\n";
    }
  }
}
