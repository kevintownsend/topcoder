// BEGIN CUT HERE

// END CUT HERE
#line 5 "Never3Steps.cc"
#include <bits/stdc++.h>

using namespace std;

uint64_t BIL = 1000*1000*1000 + 7;

class Never3Steps {
	public:
	int count(int X, int Y) {
    if (X == 0 && Y == 0) {
      return 1;
    }
		vector<pair<vector<uint64_t>, vector<uint64_t> > > dp(
        X+2, make_pair(vector<uint64_t>(4,0), vector<uint64_t>(4,0)));
		vector<pair<vector<uint64_t>, vector<uint64_t> > > dp2(
        X+1, make_pair(vector<uint64_t>(4,0), vector<uint64_t>(4,0)));

    for(int i = 1; i <= Y+1; i++) {
      for(int j = 1; j <= X+1; j++) {
        uint64_t east = 0;
        for(auto it = dp[j-1].second.begin(); it != dp[j-1].second.end(); it++) {
          east+= *it;
        }
        uint64_t north = 0;
        for(auto it = dp[j].first.begin(); it != dp[j].first.end(); it++) {
          north += *it;
        }
        vector<uint64_t> east_vec;
        east_vec.push_back(north % BIL);
        east_vec.push_back(dp[j-1].first[0]);
        east_vec.push_back(dp[j-1].first[1]);
        east_vec.push_back((dp[j-1].first[2] + dp[j-1].first[3]) % BIL);
        vector<uint64_t> north_vec;
        north_vec.push_back(east % BIL);
        north_vec.push_back(dp[j].second[0]);
        north_vec.push_back(dp[j].second[1]);
        north_vec.push_back((dp[j].second[2] + dp[j].second[3]) % BIL);
        if(i == 1 && j == 2) {
          east_vec[0]++;
        }
        if(i == 2 && j == 1) {
          north_vec[0]++;
        }

        dp[j] = make_pair(east_vec, north_vec);
      }
    }

    uint64_t ret = (dp[X+1].first[0] + dp[X+1].first[1] + dp[X+1].first[3] +
      dp[X+1].second[0] + dp[X+1].second[1] + dp[X+1].second[3]) % BIL;

    return ret;
	}
};
