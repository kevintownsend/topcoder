// BEGIN CUT HERE

// END CUT HERE
#line 5 "StringOverlap.cc"
#include <bits/stdc++.h>

using namespace std;

class StringOverlap {
	public:
	int largestOverlap(string s1, string s2) {
    int max_overlap = 0;
    cerr << "what: " << s1.size() << "\n";
    cerr << "what: " << -s2.size() << "\n";
		for(int i = s1.size(); i > -(int)s2.size(); i--) {
      cerr << "i: " << i << "\n";
      int s1_index = max(0, i);
      int s2_index = -min(0, i);
      bool match = true;
      int j = 0;
      while(s1_index < s1.size() && s2_index < s2.size()) {
        if(s1[s1_index] != s2[s2_index])
          match = false;
        s1_index++;
        s2_index++;
        j++;
      }
      if(match && j > max_overlap) {
        max_overlap = j;
      }
    }
    return max_overlap;
	}
};
