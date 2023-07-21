
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    //cerr << "WHAT: " << i << "\n";
    int n, m, k;
    cin >> n >> m >> k;
    int k_x, k_y;
    cin >> k_x >> k_y;
    int k_parity = (k_x + k_y) % 2;
    int enemies = 0;
    for(int j = 0; j < k; j++) {
      int x, y;
      cin >> x >> y;
      if((x+y) % 2 == k_parity) {
        enemies++;
      }
    }
    //cerr << "enemies: " << enemies << "\n";
    if(enemies >= 1) {
      cout << "NO\n";
    }else if(enemies == 1 && (m == 1 || n == 1)) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }

  return 0;
}
