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
    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector<int> dp(n);
    for(int i = 0; i < n; i++) {
      int pile;
      cin >> pile;
      int prev = i == 0 ? 0 : dp[i - 1] % 2;
      int k_prev = i <= k ? 0 : dp[i - k - 1] % 2;
      dp[i] = i == 0 ? 1 : (2 * prev - k_prev + 2) % 2;
      ans += (dp[i] * pile) % 2;
    }
    if(ans % 2) {
      cout << "Alice\n";
    } else {
      cout << "Bob\n";
    }
  }
}
