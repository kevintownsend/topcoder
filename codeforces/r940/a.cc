#include <iostream>
#include <map>

using namespace std;

int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    int n;
    cin >> n;
    map<int, int> totals;
    for(int j = 0; j < n; j++) {
      int length;
      cin >> length;
      totals[length]++;
    }
    int sum = 0;
    for(auto key: totals) {
      sum += key.second / 3;
    }
    cout << sum << "\n";
  }
}
