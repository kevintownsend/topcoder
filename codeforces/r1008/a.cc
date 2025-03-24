#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    int n, x;
    cin >> n >> x;
    vector<int> a;
    int sum = 0;
    for(int j = 0; j < n; j++) {
      int tmp;
      cin >> tmp;
      sum += tmp;
      a.push_back(tmp);
    }
    if(sum % n) {
      cout << "NO\n";
    } else if(sum / n == x) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
