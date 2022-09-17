// BEGIN CUT HERE

// END CUT HERE
#line 5 "WeighCoins.cc"
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

string labels = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

class WeighCoins {
	public:
	int solve(int N, vector <string> L, string result, vector <string> R) {
		set<char> higher;
		set<char> lower;

    for(int i = 0; i < N; i++) {
      higher.insert(labels[i]);
      lower.insert(labels[i]);
    }
    bool found_unequal;
    vector<char> temp;
    for(int i = 0; i < L.size(); i++) {
      switch (result[i]) {
        case '=':
          for(int j = 0; j < L[i].size(); j++) {
            higher.erase(L[i][j]);
            higher.erase(R[i][j]);
            lower.erase(L[i][j]);
            lower.erase(R[i][j]);
          }
          break;
        case '>':
          found_unequal = true;
          for(int j = 0; j < L[i].size(); j++) {
            higher.erase(R[i][j]);
            lower.erase(L[i][j]);
          }
          temp.clear();
          set_intersection(higher.begin(), higher.end(), L[i].begin(), L[i].end(), back_inserter(temp));
          higher = set<char>(temp.begin(), temp.end());
          temp.clear();
          set_intersection(lower.begin(), lower.end(), R[i].begin(), R[i].end(), back_inserter(temp));
          lower = set<char>(temp.begin(), temp.end());
          break;
        case '<':
          found_unequal = true;
          for(int j = 0; j < L[i].size(); j++) {
            higher.erase(L[i][j]);
            lower.erase(R[i][j]);
          }
          temp.clear();
          set_intersection(higher.begin(), higher.end(), R[i].begin(), R[i].end(), back_inserter(temp));
          higher = set<char>(temp.begin(), temp.end());
          temp.clear();
          set_intersection(lower.begin(), lower.end(), L[i].begin(), L[i].end(), back_inserter(temp));
          lower = set<char>(temp.begin(), temp.end());
          break;
        default:
          break;
      }
    }
    if(found_unequal) {
      double total = lower.size() + higher.size();
      if (total == 1) {
        return 0;
      }
      return ceil(log2(total)/log2(3L));
    } else {
      if (lower.size() == 1) {
        return 1;
      }
      int first = ceil(lower.size()*2/3.0L);
      return (ceil(log2(first)/log2(3L)) + 1);
    }
	}
};
