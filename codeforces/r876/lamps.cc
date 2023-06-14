#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

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
    sort(lamps.begin(), lamps.end());
    set<int> free_times;
    for(int j = 0; j < n; j++) {
      free_times.insert(j);
    }
    // TODO: complete.
  }
}
