#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  for(int t = 0; t < tt; t++) {
    int n;
    cin >> n;
    vector<int> values;
    // TODO: index of middle.
    for(int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      values.push_back(tmp);
    }
    int max_diff = 0;
    int middle = 1;
    for(int i = 1; i < n; i++) {
      int curr_diff = std::abs(values[i-1] - values[i]);
      if(curr_diff > max_diff) {
        max_diff = curr_diff;
        middle = i;
      }
    }

    vector<int> first_half_diffs;
    max_diff = 0;
    first_half_diffs.push_back(0);
    for(int i = 1; i < middle; i++) {
      int curr_diff = std::abs(values[i-1] - values[i]);
      if(curr_diff > max_diff) {
        max_diff = curr_diff;
      }
      first_half_diffs.push_back(max_diff);
    }

    vector<int> rev_first_half_diffs;
    max_diff = 0;
    rev_first_half_diffs.push_back(0);
    for(int i = middle - 1; i > 0; i--) {
      int curr_diff = std::abs(values[i-1] - values[i]);
      if(curr_diff > max_diff) {
        max_diff = curr_diff;
      }
      rev_first_half_diffs.push_back(max_diff);
    }

    vector<int> second_half_diffs;
    max_diff = 0;
    second_half_diffs.push_back(0);
    for(int i = middle + 1; i < n; i++) {
      int curr_diff = std::abs(values[i-1] - values[i]);
      if(curr_diff > max_diff) {
        max_diff = curr_diff;
      }
      second_half_diffs.push_back(max_diff);
    }

    vector<int> rev_second_half_diffs;
    max_diff = 0;
    rev_second_half_diffs.push_back(0);
    for(int i = n - 1; i > middle; i--) {
      int curr_diff = std::abs(values[i-1] - values[i]);
      if(curr_diff > max_diff) {
        max_diff = curr_diff;
      }
      rev_second_half_diffs.push_back(max_diff);
    }

    int ret = std::max({2 * rev_first_half_diffs[middle-1], std::abs(2 * values[0] - values[middle]), second_half_diffs[n - middle - 1]});
    for(int i = 1; i < middle; i++) {
      ret = std::min(ret, std::max({first_half_diffs[i-1],
            std::abs(values[i-1] - 2 * values[middle - 1]),
            2 * rev_first_half_diffs[middle - i - 1],
            std::abs(2 * values[i] - values[middle]),
            second_half_diffs[n - middle - 1]}));
    }
    ret = std::min(ret, std::abs(values[middle - 1] - values[middle]));
    for(int i = middle + 1; i < n; i++) {
      ret = std::min(ret,
          std::max({
            first_half_diffs[middle - 1],
            std::abs(values[middle - 1] - 2 * values[i - 1]),
            2 * second_half_diffs[i - 1 - middle],
            std::abs(2 * values[middle] - values[i]),
            rev_second_half_diffs[n - i - 1]}));
    }
    ret = std::min(ret, std::max({
            first_half_diffs[middle - 1],
            std::abs(values[middle - 1] - 2 * values[n - 1]),
            2 * second_half_diffs[n - middle - 1]}));

    cout << ret << '\n';
  }
}
