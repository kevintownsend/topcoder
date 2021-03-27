#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int t;
  std::cin >> t;
  for (int test = 0; test < t; ++test) {
    int n;
    int cost;
    std::cin >> n >> cost;
    std::vector<int> list;
    for (int i = 0; i < n; ++i) {
      list.push_back(i);
    }
    cost -= n-1;
    if (cost < 0) {
      std::cout << "Case #" << (test + 1) << ": IMPOSSIBLE\n";
      continue;
    }

    for (int i = n-1; i >= 0; --i) {
      if (cost > (n - i - 1)) {
        std::reverse(list.begin() + i, list.end());
        cost -= (n - i - 1);
      } else {
        std::reverse(list.begin() + i, list.begin() + i + cost + 1);
        cost = 0;
      }
    }
    if (cost > 0) {
      std::cout << "Case #" << (test + 1) << ": IMPOSSIBLE\n";
    } else {
      std::cout << "Case #" << (test + 1) << ":";
      for (int i = 0; i < list.size(); ++i) {
        std::cout << " " << (list[i] + 1);
      }
      std::cout << "\n";

    }
  }
}
