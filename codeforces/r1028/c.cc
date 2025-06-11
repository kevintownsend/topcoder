#include <bits/stdc++.h>

using namespace std;

// TODO: debug code.

int main() {
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int g = 0;
    // TODO: find gcd
    for(int i = 0; i < n; i++) {
      g = gcd(g, a[i]);
    }
    cerr << "g: " << g << "\n";
    // TODO: use dp to find moves
    // TODO: find largest value
    int m = *max_element(a.begin(), a.end());
    vector<int> dp(m, n + 1);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        int next_gcd = gcd(j, a[i]);
        dp[next_gcd] = min(dp[next_gcd], dp[j] + 1);
      }
    }

    // TODO: calculate ops.
    int ops = dp[g] - 1;
    for(int i = 0; i < n; i++) {
      if(a[i] != g)
        ops++;
    }
    cout << ops << "\n";
  }
  return 0;
}
