#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    //if(i == 2) cerr << "WTF\n";
    int n;
    cin >> n;
    //cerr << "n: " << n << "\n";
    vector<int> a(n), b(n);
    for(int &tmp: a) cin >> tmp;
    //cerr << " " << a[j];
    //cerr << "\n";
    for(int &tmp: b) cin >> tmp;
    //cerr << " " << b[j];
    //cerr << "\n";
    // TODO: complete.
    int prev_a = a[0];
    int prev_b = b[0];
    int tot_a = 1;
    int tot_b = 1;
    map<int, int> max_a, max_b;

    for(int j = 1; j < n; j++) {
      //cerr << "wtf:\n";
      //cerr << "a:" << a[j] << "\n";
      if(prev_a == a[j]) {
        tot_a++;
      }else {
        if(max_a[a[j-1]] < tot_a) {
          max_a[a[j-1]] = tot_a;
          //cerr << "a\n";
          //cerr << a[j-1] << " " << tot_a << "\n";
        }
        tot_a = 1;
      }
      if(prev_b == b[j]) {
        //cerr << "fuck you\n";
        tot_b++;
      } else {
        if(max_b[b[j-1]] < tot_b) {
          max_b[b[j-1]] = tot_b;
          //cerr << "b\n";
          //cerr << b[j-1] << " " << tot_b << "\n";
        }
        tot_b = 1;
      }
      prev_a = a[j];
      prev_b = b[j];
    }
    if(max_a[a[n-1]] < tot_a)
      max_a[a[n-1]] = tot_a;
    //cerr << a[n-1] << " " << tot_a << "\n";
    if(max_b[b[n-1]] < tot_b)
      max_b[b[n-1]] = tot_b;
    //cerr << b[n-1] << " " << tot_b << "\n";
    //cerr << "go to hell: " << max_b[1] << "\n";
    //cerr << "merging\n";
    for(auto const& [key, value]: max_b) {
      //cerr << key << ":" << value << "\n";
      //cerr << ":" << max_a[key] << "\n";
      max_a[key] += value;
      //cerr << ":" << max_a[key] << "\n";
    }
    cout << max_element(max_a.begin(), max_a.end(), [](pair<int, int> x, pair<int, int> y) {return x.second < y.second;})->second << "\n";
  }
}
