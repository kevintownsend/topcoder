#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


// TODO: fix
// turn on weakest lamps first, greedily.

int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<pair<int, int> > lamps(n);
    for(auto &lamp: lamps) {
      cin >> lamp.second >> lamp.first;
    }
    sort(lamps.begin(), lamps.end(), [](pair<int, int> x, pair<int, int> y) {return x.first > y.first;});
    set<int> free_times;
    for(int j = 0; j < n; j++) {
      free_times.insert(j);
    }
    cerr << "first: " << lamps[0].first << " " << lamps[0].second << "\n";
    // TODO: complete.
    int ret = 0;
    for(auto lamp: lamps) {
      auto after = free_times.upper_bound(lamp.second-1);
      if(after == free_times.begin())
        continue;
      after--;
      cerr << "added: " << lamp.first << "at" << *after << "\n";
      free_times.erase(after);
      ret += lamp.first;
    }
    cout << ret << "\n";
  }
}
