/**
 * author: Kevin Townsend
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  for(int t = 0; t < tt; t++) {
    int n;
    cin >> n;
    cout << (2*n-1) << '\n';
    for(int i = 0; i < n; i++) {
      cout << (i+1) << " " << (i+1) << " " << n << '\n';
    }
    for(int i = 1; i < n; i++) {
      cout << (i+1) << " " << 1 << " " << i << '\n';
    }
  }
}

