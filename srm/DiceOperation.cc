// BEGIN CUT HERE

// END CUT HERE
#line 5 "DiceOperation.cc"
#include <bits/stdc++.h>

using namespace std;

class DiceOperation {
  private:
  int xor_bits(int a) {
    int ret = 0;
    while(a) {
      ret ^= a&1;
      a>>=1;
    }
    return ret;
  }


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
      for(int j = 0; j < i<<dice.size(); j++) {
        int use = xor_bits(j);
        double prob_comb = 1.0L;
        for(int k = 0; k < dice.size(); k++) {
          if((i>> j) & 1) {
            prob_comb *= prob[k][i];
          } else {
            prob_comb *= 1 - prob[k][i];
          }
        }
        if (use) {
          ret += (1<<i) * prob_comb;
        }
        // TODO: xor
        // TODO: if 1
        // calc prob
        // Add to ret
      }
    }
    return ret;
	}
};
