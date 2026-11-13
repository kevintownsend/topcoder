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
    vector<int> ans(n);
    bool valid = true;
    for(int i = 0; i < n; i++) {
      int p;
      cin >> p;
      int value = n - i + p;
      //ans[i] = value;
      if(!(value > 0 && value <=n)) {
        valid = false;
      } else {
        ans[value - 1] = i + 1;
      }
      if(!dp.count(value)) {
        dp.insert(value);
      } else {
        valid = false;
      }
    }
    if(valid) {
      for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
      }
      cout << "\n";
    } else {
      cout << "-1\n";
    }
  }
}
