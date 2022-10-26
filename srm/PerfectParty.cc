#line 5 "PerfectParty.cc"
#include <bits/stdc++.h>

using namespace std;

class PerfectParty {
	public:
	long long invite(vector <int> candies) {
		map<pair<int, int>, int> dp;
		map<pair<int, int>, int> dp2;
    dp[make_pair(1,0)] = 1;
    dp2[make_pair(1,0)] = 1;
    for(int new_guy: candies) {
      for(auto key: dp) {
        pair<int, int> new_key = make_pair(key.first.first + 1, key.first.second + new_guy);
        dp2[new_key] += key.second;
      }
      dp = dp2;
    }
    int ret = 0;
    for(auto key_value: dp) {
      if(key_value.first.second % key_value.first.first == 0) {
        ret+= key_value.second;
      }
    }
    return ret;
	}
};


// Powered by FileEdit
