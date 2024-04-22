#include <iostream>
#include <bit>

using namespace std;

// TODO: got furustrated. The problem is a bit trickier.
// looking back it's not that hard.
// I still did it wrong. Didn't see that 0 was valid. Shake it off.
int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    if(n == 1) {
      cout << k << "\n";
      continue;
    }
    // TODO: efficently use numbers
    int rest = k;
    int used = 0;
    int remainder = 0;
    for(int j = 1; j < (rest-n+1+used); j <<= 1) {
      if(n - used > 2) {
        cout << j << " ";
        used++;
      } else {
        remainder |= j;
      }
      rest -= j;
    }
    cout << remainder << " ";
    used++;
    while(used < n - 1) {
      cout << 1 << " ";
      rest--;
      used++;
    }
    cout << rest << "\n";
  }
}
