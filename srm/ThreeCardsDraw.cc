// BEGIN CUT HERE

// END CUT HERE
#line 5 "ThreeCardsDraw.cc"
#include <bits/stdc++.h>

using namespace std;

class ThreeCardsDraw {
	public:
	double totalChance(int total) {
    int bottom = 52*51*50;
    map<int, int> totals;
		for(int i = 0; i < 52; i++) {
      int i_value = i % 13 + 1;
      if(i_value > 10) {
        i_value = 10;
      }
      for(int j = 0; j < 52; j++) {
        if(i == j)
          continue;
        int j_value = j % 13 + 1;
        if(j_value > 10) {
          j_value = 10;
        }
        for(int k = 0; k < 52; k++) {
          if(k == i)
            continue;
          if(k == j)
            continue;
          int k_value = k % 13 + 1;
          if(k_value > 10) {
            k_value = 10;
          }
          totals[i_value+j_value+k_value]++;
        }
      }
    }
    return 1.0L * totals[total] / bottom;
	}
};
