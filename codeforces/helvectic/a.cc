#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;
  vector<tuple<int, int, char> > values;
  int balance = 0;
  for(int i = 0; i < (int)s.size(); i++) {
    values.emplace_back(i, balance, s[i]);
    if(s[i] == '(')
      balance++;
    else
      balance--;
  }
  sort(values.begin(), values.end(), [](tuple<int, int, char> &a, tuple<int, int, char> &b) {return get<1>(a) == get<1>(b) ? get<0>(a) > get<0>(b) : get<1>(a) < get<1>(b);});
  for(int i = 0; i < (int)values.size(); i++) {
    cout << get<2>(values[i]);
  }
  cout << "\n";
}
