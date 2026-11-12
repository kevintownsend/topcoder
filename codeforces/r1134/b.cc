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
    string letters;
    cin >> letters;
    int ans = letters[0] == 'B';
    for(int i = 1; i < n; i++) {
      if(letters[i] == letters[i-1])
        ans++;
    }
    cout << ans << '\n';
  }
}
