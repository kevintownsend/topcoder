// BEGIN CUT HERE

// END CUT HERE
#line 5 "OneCardDraw.cc"
#include <bits/stdc++.h>

using namespace std;

class OneCardDraw {
	public:
	double pickChance(vector <int> cards, int target) {
		int top = 0;
    for(int card: cards) {
      if(card == target) {
        top++;
      }
    }
    return 1.0L * top / cards.size();
	}
};
