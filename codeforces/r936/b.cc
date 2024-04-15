#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    int64_t curr_total = 0;
    int64_t curr_min = 0;
    int64_t curr_max = 0;
    int64_t curr_max_diff = 0;
    for(int j = 0; j < n; j++){
      int val;
      cin >> val;
      curr_total += val;
      if(curr_min > curr_total) {
        curr_max = curr_total;
        curr_min = curr_total;
      }
      curr_max = max(curr_max, curr_total);
      curr_max_diff = max(curr_max_diff, curr_max-curr_min);
    }
    int64_t ans = curr_max_diff % (1000000007);
    for(int j = 0; j < k; j++){
      ans = (ans * 2) % 1000000007;
    }
    ans = (1000000007 + ans + curr_total - curr_max_diff) % 1000000007;
    if(ans < 0)
      ans += 1000000007;
    cout << ans << "\n";
  }
}

