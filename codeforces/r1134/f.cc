/**
 * author: Kevin Townsend
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  for (int t = 0; t < tt; t++) {
    int n;
    cin >> n;
    set<int> dp;
    // TODO: complete (ran out of time).
    for(int i = 0; i < n; i++) {
      int p;
      cin >> p;
      int value = n - i + p;
      if(dp.count(n - i + p)) {

      }
    }
  }
}
