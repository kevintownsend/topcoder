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
    vector<int> stones(3);
    for(int i = 0; i < 3; i++) {
      cin >> stones[i];
    }
    sort(stones.begin(), stones.end());
    if(stones[1] == stones[0] + 1 && stones[2] == stones[0] + 2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
