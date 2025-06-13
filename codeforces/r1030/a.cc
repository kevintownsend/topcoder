/**
 * author: Kevin Townsend
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  for(int t = 0; t < tt; t++) {
    int n, k;
    cin >> n >> k;
    for(int j = 0; j < k; j++) {
      cout << '1';
    }
    for(int j = 0; j < n-k; j++) {
      cout << '0';
    }
    cout << '\n';
  }
}

