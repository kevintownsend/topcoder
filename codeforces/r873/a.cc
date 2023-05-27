#include <iostream>
#include <vector>

using namespace std;

// TODO: write code on paper.
int main() {
  int t, n;
  cin >> t >> n;
  for(int i = 0; i < t; i++) {
    int tmp;
    vector<int> lower;
    vector<int> values;
    for(int j = 0; j < n; j++) {
      cin >> tmp;
      values.push_back(tmp);
    }
    for(int j = 0; j < n; j++) {
      cin >> tmp;
      lower.push_back(tmp);
    }
    // TODO: sort lower.
    // TODO: choose math.
  }
}
