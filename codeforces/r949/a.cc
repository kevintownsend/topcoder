#include <iostream>
#include <bit>

using namespace std;

int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    unsigned int l, r;
    cin >> l >> r;
    cout << bit_width(r)-1 << "\n";
  }
}
