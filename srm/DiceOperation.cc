// BEGIN CUT HERE

// END CUT HERE
#line 5 "DiceOperation.cc"
#include <bits/stdc++.h>

using namespace std;

class DiceOperation {
	public:
	double solve(vector <int> dice) {
		// sum of expected value for each bit.
    double ret = 0;
    vector<vector<double> > prob(dice.size(), vector<double>(9, 0.0));
    for(int i = 0; i < 9; i++) {
      int j = 0;
      for(int die: dice) {
        int full_blocks = (die)/(1<<(i+1));
        int ones = full_blocks* (1<<i);
        int left_over = (die)%(1<<(i+1));
        if (left_over > (1<<i) - 1) {
          ones += left_over - (1<<i) + 1;
        }
        prob[j][i] = 1.0L * ones / die;
        j++;
      }
      // TODO: for each combination.
      for(int i = 0; i < i<<9; i++) {
        // TODO: xor
        // TODO: if 1
        // calc prob
        // Add to ret
      }
    }
	}
};
