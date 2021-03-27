#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int t;
  std::cin >> t;
  for (int test = 0; test < t; ++test) {
    int n;
    std::cin >> n;
    std::vector<int> list;
    for (int i = 0; i < n; ++i) {
      int input;
      std::cin >> input;
      list.push_back(input);
    }
    int total = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        std::cerr << list[j] << " ";
      }
      std::cerr << "\n";
      int min = list[i];
      int minj = i;
      for (int j = i; j < n; ++j) {
        if (list[j] <= min) {
          min = list[j];
          minj = j;
        }
      }
      std::cerr << "i:" << i << " j:" << minj << "\n";

      for (int j = 0; j < n; ++j) {
        std::cerr << list[j] << " ";
      }
      std::cerr << "\n";
      std::reverse(list.begin() + i, list.begin() + minj + 1);
      std::cerr << "after\n";
      for (int j = 0; j < n; ++j) {
        std::cerr << list[j] << " ";
      }
      std::cerr << "\n";
      total += (minj-i);
    }
    std::cout << "Case #" << (test + 1) << ": " << (total +n- 1) << "\n";
  }
}
