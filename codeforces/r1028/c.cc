#include <bits/stdc++.h>

using namespace std;

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
    // find gcd
    for(int i = 0; i < n; i++) {
      g = gcd(g, a[i]);
    }
    // use dp to find moves
    // find largest value
    int m = *max_element(a.begin(), a.end());
    vector<int> dp(m + 1, n + 1);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        int next_gcd = gcd(j, a[i]);
        dp[next_gcd] = min(dp[next_gcd], dp[j] + 1);
      }
    }

    // calculate ops.
    int ops = dp[g] - 1;
    if(dp[g] > 1)
      ops--;
    for(int i = 0; i < n; i++) {
      if(a[i] != g)
        ops++;
    }
    cout << ops << "\n";
  }
  return 0;
}
