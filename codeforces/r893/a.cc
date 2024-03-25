#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    uint64_t a, b, c;
    cin >> a >> b >> c;
    uint64_t total = a+b+c;
    uint64_t second = b + c/2;
    uint64_t first = a + c - c/2;
    if(first > second)
      cout << "First\n";
    else
      cout << "Second\n";
  }

}
