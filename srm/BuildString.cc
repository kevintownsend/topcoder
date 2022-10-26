// BEGIN CUT HERE

// END CUT HERE
#line 5 "BuildString.cc"
#include <bits/stdc++.h>

using namespace std;

class BuildString {
	public:
	string isPossible(vector <string> parts, string target) {
		vector<bool> dp(target.size() + 1, false);
    dp[0] = true;
    for(int i = 0; i < target.size(); i++) {
      if(!dp[i]) {
        continue;
      }
      for(string part: parts) {
        if(i+part.size() > target.size())
          continue;
        if(part == target.substr(i, part.size())) {
          dp[i+part.size()] = true;
          cerr << "wtf: " << i << "\n";
        }
      }
    }
    if(dp[target.size()]) {
      return "YES";
    } else {
      return "NO";
    }
	}
};
