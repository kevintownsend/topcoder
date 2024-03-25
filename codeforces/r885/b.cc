#include <iostream>
#include <vector>
#include <cinttypes>
#include <climits>
#include <set>

using namespace std;

int main() {
  int t;
  cin >> t;
  cerr << (1 >> -2) << "\n";
  for(int iout = 0; iout < t; iout++) {
    //cerr << "test: " << iout << "\n";
    int n, k;
    cin >> n >> k;
    vector<multiset<int> > maximums(k, multiset<int>());
    vector<int> last(k, 0);
    int color;
    for(int i = 0; i < n; i++) {
      cin >> color;
      color--;
      maximums[color].insert(i + 1 - last[color]);
      last[color] = i+1;
    }
    //cerr << "wtf\n";
    for(int i = 0; i < k; i++) {
      maximums[i].insert(n + 1 - last[i]);
    }
    int ret = INT_MAX;
    for(int i = 0; i < k; i++) {
      //TODO: find max step for each.
      int j = 0;
      //cerr << "size: " << maximums[i].size() << "\n";
      auto it = maximums[i].rbegin();
      int first = (*it + 1) / 2;
      //cerr << "first: " << first << "\n";
      it++;
      int second = *it;
      //cerr << "second: " << second << "\n";
      ret = min(max(first, second), ret);
    }
    cout << ret-1 << "\n";
  }
}
