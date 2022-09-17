// BEGIN CUT HERE
// 13 min solve.

// END CUT HERE
#line 5 "OptimalMemoryGame.cc"
#include <string>
#include <vector>
#include <set>

using namespace std;

class OptimalMemoryGame {
	public:
	int findPairs(string known) {
    int unknown = 0;
    int num_known = 0;
    int ret = 0;
    set<char> seen;
		for(int i = 0; i < known.size(); i++) {
      if(known[i] == '-') {
        unknown++;
      }else {
        if(seen.insert(known[i]).second) {
          num_known++;
        } else {
          ret++;
          num_known--;
        }
      }
    }
    if(unknown == num_known) {
      ret += unknown;
    } else if(unknown == 2) {
      ret += 1;
    }
    return ret;
	}
};
