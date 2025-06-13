/**
 * author: Kevin Townsend
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  for(int t = 0; t < tt; t++) {
    int64_t n, k;
    cin >> n >> k;
    // TODO: read a
    vector<int64_t> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    // TODO: go through 60 bits.
    int64_t beauty = 0;
    for(int i = 0; i < 60; i++) {
      for(int j = 0; j < n; j++) {
        if((a[j]>>i) & 1) {
          beauty++;
        }else if(k >= (1LL << i)) {
          k -= (1LL << i);
          beauty++;
        }
      }
    }
    cout << beauty << "\n";
  }
}

