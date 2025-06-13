/**
 * author: Kevin Townsend
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  for(int t = 0; t < tt; t++) {
   int m, n;
    cin >> n >> m;
    // find mid
    pair<int, int> mid = make_pair(m/2, n/2);
    cout << mid.first << " " << mid.second;
    for(int i = 1; i <= max(m, n)/2; i++) {
      for(int j = 0; j <= i; j++){
        // TODO: 'knight moves' clockwise
        int x = mid.first - i;
        int y = mid.second + j;
        // TODO: print colored.
        x = mid.first + i;
        y = mid.second - j;
        x = mid.first + j;
        y = mid.second + i;
        x = mid.first - j;
        y = mid.second - i;

        // TODO: 'knight moves' counter clockwise
        if(j != 0 && i != j) {
          x = mid.first - j;
          y = mid.second + i;
          x = mid.first + j;
          y = mid.second - i;
          x = mid.first + i;
          y = mid.second + j;
          x = mid.first - i;
          y = mid.second - j;
        }
      }
      // TODO: edges and coners.
    }
  }
}

