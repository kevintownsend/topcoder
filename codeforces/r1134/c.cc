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
    vector<int> books(n);
    for(int i = 0; i < n; i++) {
      cin >> books[i];
    }
    sort(books.begin(), books.end());
    multiset<int> bookset(books.begin(), books.end());
    int ans = 0;
    for(auto it = bookset.begin(); it != bookset.end(); it = bookset.upper_bound(*it)) {
      if(bookset.count(*it) > 2)
        ans += 2;
      else
        ans += bookset.count(*it);
    }
    cout << ans << '\n';

    vector<int> leftovers;
    cout << books[0] << ' ';
    for(int i = 1; i < n; i++) {
      if(books[i - 1] == books[i])
        leftovers.push_back(books[i]);
      else
        cout << books[i] << ' ';
    }
    for(int i = leftovers.size() - 1; i >= 0; i--) {
      cout << leftovers[i] << ' ';
    }
    cout << '\n';
  }
}
