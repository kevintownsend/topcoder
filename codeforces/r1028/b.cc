#include <iostream>
#include <vector>
#include <cstdint>

#define LARGE_NUMBER 998244353

using namespace std;

int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<uint64_t> converted_p(n, 1);
    for(int j = 0; j < n; j++) {
      uint64_t p;
      cin >> p;
      for(uint64_t k = 0; k < p; k++) {
        converted_p[j] *= 2;
        converted_p[j] %= LARGE_NUMBER;
      }
    }
    vector<int> converted_q(n, 1);
    for(int j = 0; j < n; j++) {
      uint64_t q;
      cin >> q;
      for(uint64_t k = 0; k < q; k++) {
        converted_q[j] *= 2;
        converted_q[j] %= LARGE_NUMBER;
      }
    }
    // TODO: complete.
  }
}
