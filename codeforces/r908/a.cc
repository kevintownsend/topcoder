
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    vector<int64_t> b;
    for(int j = 0; j < n; j++) {
      int64_t tmp;
      cin >> tmp;
      b.push_back(tmp);
    }
    map<int, int> edges;
    for(int j = 0; j < n; j++) {
      if(b[j] > n)
        continue;
      int to_offset = (b[j]%n - 1 - j + n) % n;
      int from_offset = (to_offset - b[j]%n + n) % n;
      //cerr << "to: " << to_offset << "from: " << from_offset << "\n";
      edges[from_offset] = to_offset;

    }
    int curr = 0;
    int count = 0;
    k = min(k, n);
    bool dead = false;
    while(count <= k) {
      //cerr << "count: " << count << "\n";
      auto it = edges.find(curr);
      if(it == edges.end()) {
        dead = true;
        break;
      }
      curr = edges[curr];
      count++;
    }
    if(dead) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
    //TODO: continue.

  }

}
