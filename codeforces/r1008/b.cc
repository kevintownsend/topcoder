#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    if(k % 2) {
      for(int j = 0; j < n; j++) {
        if(j == n - 1) {
          cout << (n - 1);
        } else {
          cout << n << " ";
        }
      }
    } else {
      for(int j = 0; j < n; j++) {
        if(j == n - 2) {
          cout << n  << " ";
        } else {
          cout << n - 1 << " ";
        }
      }
    }
    cout << "\n";
  }
}
