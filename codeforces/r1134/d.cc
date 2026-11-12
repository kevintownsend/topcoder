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
    string s;
    cin >> s;
    vector<bool> moves(26, false);
    for(int l = 0, r = n - 1; l < r; l++, r--) {
      char lo = s[l];
      char hi = s[r];
      if(hi < lo)
        swap(hi, lo);
      for(int i = lo + 1; i <= hi; i++) {
        moves[i - 'a'] = true;
      }
    }
    int ans = 0;
    for(int i = 0; i < 26; i++) {
      if(moves[i])
        ans++;
    }
    cout << ans << '\n';
  }
}
