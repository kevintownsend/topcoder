/**
 * author: Kevin Townsend (AI-assisted reference)
 * note: Post-contest review / simplified implementation of a.cc
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    // pref[i] = max adjacent diff in a[0..i]
    // suff[i] = max adjacent diff in a[i..n-1]
    vector<int> pref(n, 0), suff(n, 0);
    int middle = 1;
    for (int i = 1; i < n; i++) {
      int d = abs(a[i - 1] - a[i]);
      pref[i] = max(pref[i - 1], d);
      if (d > abs(a[middle - 1] - a[middle])) {
        middle = i;
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      suff[i] = max(suff[i + 1], abs(a[i] - a[i + 1]));
    }

    int ret = pref[n - 1];  // No operation

    // Case 1: reverse and double a[l .. middle - 1]
    int inner_max = 0;
    for (int l = middle - 1; l >= 0; l--) {
      if (l + 1 <= middle - 1) {
        inner_max = max(inner_max, abs(a[l] - a[l + 1]));
      }
      int left_outer  = (l > 0) ? pref[l - 1] : 0;
      int left_join   = (l > 0) ? abs(a[l - 1] - 2 * a[middle - 1]) : 0;
      int right_join  = abs(2 * a[l] - a[middle]);
      int right_outer = suff[middle];
      ret = min(ret, max({left_outer, left_join, 2 * inner_max, right_join, right_outer}));
    }

    // Case 2: reverse and double a[middle .. r]
    inner_max = 0;
    for (int r = middle; r < n; r++) {
      if (r - 1 >= middle) {
        inner_max = max(inner_max, abs(a[r - 1] - a[r]));
      }
      int left_outer  = pref[middle - 1];
      int left_join   = abs(a[middle - 1] - 2 * a[r]);
      int right_join  = (r + 1 < n) ? abs(2 * a[middle] - a[r + 1]) : 0;
      int right_outer = (r + 1 < n) ? suff[r + 1] : 0;
      ret = min(ret, max({left_outer, left_join, 2 * inner_max, right_join, right_outer}));
    }

    cout << ret << '\n';
  }
}
