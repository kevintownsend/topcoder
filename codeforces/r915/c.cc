#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    int n;
    string s;
    cin >> n >> s;
    // TODO: find number of ops
    // TODO: find final string
    string s_copy = s;
    char curr = 'a' - 1;
    vector<int> indices;
    for(int j = n - 1; j >= 0; j--) {
      if(s[j] > curr) {
        indices.push_back(j);
        curr = s[j];
      }
    }
    for(int j = 0; j < indices.size(); j++) {
      swap(s[indices[j]], s[indices[n-j - 1]]);
    }
    cerr << s << "\n";
  }
}
