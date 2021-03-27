#include <iostream>
#include <vector>

int main() {
  int t, n, q;
  std::cin >> t >> n >> q;
  for (int test = 0; test < t; ++test) {
    std::vector<int> list;
    for (int i = 0; i < n; ++i) {
      list.push_back(i);
    }
    for (int i = 2; i < n; ++i) {
      // TODO: find insertion location
      int low = 0;
      int hi = i;
      while (hi > low) {
        std::cerr << "low: " << low << "\n";
        std::cerr << "hi: " << hi << "\n";
        int mid = (hi - 1 + low) / 2;
        if (mid > hi - 2) {
          mid = hi - 2;
        }
        if (mid < 0) {
          mid = 0;
        }
        std::cout << (list[mid] + 1) << " " << (list[mid+1] + 1) << " " << (list[i] + 1) << "\n";
        int res;
        std::cin >> res;
        --res;
        if (res == -1) {
          exit(0);
        } else if (res == list[mid]) {
          hi = mid;
        } else if (res == list[mid+1]) {
          low = mid + 2;

        } else if (res == list[i]) {
          low = mid + 1;
          break;
        } else {
          exit(-1);
        }
      }
      int temp = list[i];
      for (int j = i; j > low; --j) {
        list[j] = list[j-1];
      }
      list[low] = temp;
    }
    std::cout << (list[0] + 1);
    for(int i = 1; i < list.size(); ++i) {
      std::cout << " " << (list[i] + 1);
    }
    std::cout << "\n";
    int res;
    std::cin >> res;
  }
}
