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
    // TODO: positions
    vector<int64_t> p(n);
    for(int i = 0; i < n; i++) {
      cin >> p[i];
    }
    // TODO: delays
    vector<int64_t> d(n);
    for(int i = 0; i < n; i++) {
      cin >> d[i];
    }
    // TODO: starting position
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
      int64_t query;
      cin >> query;
      // TODO: bisect p.
      // TODO: calculate time.
    }
    // TODO: calculate first light
    // TODO: calculate next lights
    // TODO: find loops.
  }
}

