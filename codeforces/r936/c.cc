#include <iostream>
#include <vector>

using namespace std;

// TODO: fix time limit exceeded issue.

tuple<int, int> dfs(int curr, int prev, vector<vector<int>> &tree, int k) {
  int x = 0;
  int total = 1;
  for(int i = 0; i < tree[curr].size(); i++) {
    if(tree[curr][i] == prev)
      continue;
    int sub_x, sub_total;
    tie(sub_x, sub_total) = dfs(tree[curr][i], curr, tree, k);
    x += sub_x;
    total += sub_total;
  }
  if(total >= k) {
    total = 0;
    x++;
  }

  return make_tuple(x, total);
}

bool check(int k, int x, vector<vector<int>> &tree) {
  int cc;
  tie(cc, ignore) = dfs(0, -1, tree, x);
  return cc >= k + 1;
}

int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> tree(n);
    for(int j = 0; j < n - 1; j++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      tree[u].push_back(v);
      tree[v].push_back(u);
    }
    // TODO: complete.
    int hi = n, lo = 1;
    while(hi != lo) {
      int mid = hi+lo / 2;
      if(check(k, mid, tree)) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    cout << hi << "\n";
  }
}
