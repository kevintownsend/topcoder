// BEGIN CUT HERE

// END CUT HERE
#line 5 "TwoCardsDraw.cc"
#include <bits/stdc++.h>

using namespace std;

class TwoCardsDraw {
	public:
	double primeChance(vector <int> cards) {
	  int bottom = cards.size() * cards.size();
    int top = 0;
    for(int card1: cards) {
      for(int card2: cards) {
        int total = card2;
        if(card2 < 10) {
          total += card1*10;
        } else {
          total += card1*100;
        }
        for(int i = 2; i < total; i++) {
          if(total % i == 0) {
            top++;
            break;
          }
        }
      }
    }
    return 1.0L * (bottom - top) / bottom;
	}
};
