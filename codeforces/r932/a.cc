#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    int n;
    string s;
    cin >> n;
    cin >> s;
    string r = s;
    reverse(r.begin(), r.end());
    string ret;
    if(n % 2) {
      if(r <= s) {
        cout << r << "\n";
      } else {
        cout << s << r << "\n";
      }
    } else {
      if(r < s) {
        cout << r << s << "\n";
      } else {
        cout << s << "\n";
      }
    }

  }
}
