#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t, n;
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> n;
    int tmp;
    vector<int> lower;
    vector<int> values;
    for(int j = 0; j < n; j++) {
      cin >> tmp;
      values.push_back(tmp);
    }
    for(int j = 0; j < n; j++) {
      cin >> tmp;
      lower.push_back(tmp);
    }
    sort(values.begin(), values.end());
    sort(lower.begin(), lower.end());

    uint64_t ret = 1;
    int j = 0;
    int k = 0;
    for(int value : values) {
      while(j != n && lower[j] < value) {
        j++;
      }
      ret = (ret * (j - k)) % (1000000000ULL + 7);
      k++;
    }
    cout << ret << "\n";
  }
}
