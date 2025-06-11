#include <iostream>
#include <vector>
#include <cstdint>

#define LARGE_NUMBER 998244353

using namespace std;

uint64_t convert(pair<uint64_t, uint64_t> value) {
  uint64_t first = 1;
  for(uint64_t i = 0; i < value.first; i++) {
    first *= 2;
    first %= LARGE_NUMBER;
  }
  uint64_t second = 1;
  for(uint64_t i = 0; i < value.second; i++) {
    second *= 2;
    second %= LARGE_NUMBER;
  }
  return (first + second) % LARGE_NUMBER;
}

int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<uint64_t> p(n);
    for(int j = 0; j < n; j++) {
      cin >> p[j];
    }
    vector<uint64_t> q(n);
    for(int j = 0; j < n; j++) {
      cin >> q[j];
    }
    vector<uint64_t> r(n);
    pair<uint64_t, int> max_p = make_pair(p[0], 0);
    pair<uint64_t, int> max_q = make_pair(q[0], 0);
    for(int j = 0; j < n; j++) {
      if(p[j] > max_p.first) {
        max_p.first = p[j];
        max_p.second = j;
      }
      if(q[j] > max_q.first) {
        max_q.first = q[j];
        max_q.second = j;
      }
      if(max_q.first == max_p.first) {
        cout << convert(make_pair(max_q.first, max(q[j-max_p.second], p[j-max_q.second]))) << " ";
      } else if(max_q.first > max_p.first) {
        cout << convert(make_pair(max_q.first, p[j-max_q.second])) << " ";
      } else {
        cout << convert(make_pair(max_p.first, q[j-max_q.second])) << " ";
      }
    }
    cout << "\n";
  }
}
