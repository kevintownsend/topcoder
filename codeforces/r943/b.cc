#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    int a_length, b_length;
    cin >> a_length >> b_length;
    string a, b;
    cin >> a >> b;
    int a_index = 0;
    int b_index = 0;
    int sum = 0;
    while(a_index < a_length && b_index < b_length) {
      if(a[a_index] == b[b_index]) {
        a_index++;
        sum++;
      }
      b_index++;
    }
    cout << sum << "\n";

  }
}
