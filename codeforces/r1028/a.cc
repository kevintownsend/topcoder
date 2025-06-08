#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(min(a, c) >= min (b, d)) {
      cout << "Gellyfish\n";
    } else {
      cout << "Flower\n";
    }
  }
}
