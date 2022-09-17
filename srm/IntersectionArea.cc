// BEGIN CUT HERE

// END CUT HERE
#line 5 "IntersectionArea.cc"
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

class IntersectionArea {
	public:
	vector <int> addOne(vector <int> X1, vector <int> Y1, vector <int> X2, vector <int> Y2, long long A) {
    set<int> x_breaks;
    set<int> y_breaks;

    for(int i = 0; i < X1.size(); i++) {
      x_breaks.insert(X1[i]);
      x_breaks.insert(X2[i]);
      y_breaks.insert(Y1[i]);
      y_breaks.insert(Y2[i]);
    }

    map<int, int> x_breaks_index;
    int i = 0;
    for(auto it = x_breaks.begin(); it != x_breaks.end(); it++) {
      x_breaks_index[*it] = i;
      i++;
    }
    map<int, int> y_breaks_index;
    i = 0;
    for(auto it = y_breaks.begin(); it != y_breaks.end(); it++) {
      y_breaks_index[*it] = i;
      i++;
    }
    vector<vector<bool> > overlap(y_breaks.size() - 1, vector<bool>(x_breaks.size() - 1, false));

    for(int i = 0; i < X1.size(); i++) {
      for(int j = 0; j < X1.size(); j++) {
        int x_low = x_breaks_index[max(X1[i], X1[j])];
        int y_low = y_breaks_index[max(Y1[i], Y1[j])];
        int x_high = x_breaks_index[min(X2[i], X2[j])];
        int y_high = y_breaks_index[min(Y2[i], Y2[j])];
        if(x_low < x_high && y_low < y_high) {
          for(int i2 = y_low; i2 < y_high; i2++) {
            for(int j2 = x_low; j2 < x_high; j2++) {
              overlap[i2][j2] = true;
            }
          }
        }
      }
    }
    vector<int> ret;

		return ret;
	}
};
