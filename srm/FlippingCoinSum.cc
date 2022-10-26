// BEGIN CUT HERE

// END CUT HERE
#line 5 "FlippingCoinSum.cc"
#include <bits/stdc++.h>

using namespace std;

class FlippingCoinSum {
	public:
	vector <int> flip(vector <int> faceUp, vector <int> faceDown, int goal) {
    int initial_sum = accumulate(faceUp.begin(), faceUp.end(), 0);
    vector<pair<int, pair<vector<bool>, vector<bool> > > > dp(100001, make_pair(-1, make_pair(vector<bool>(),vector<bool>())));

    dp[initial_sum] = make_pair(0, make_pair(vector<bool>(faceUp.size(), false), vector<bool>(faceDown.size(), false)));

    queue<int> dp_stack;
    dp_stack.push(initial_sum);

    while(!dp_stack.empty()) {
      int curr = dp_stack.front();
      dp_stack.pop();
      for(int i = 0; i < faceUp.size(); i++) {
        bool flipped = dp[curr].second.first[i];
        if(flipped)
          continue;
        dp[curr].second.first[i] = true;
        int flip_index = curr - faceUp[i];
        if(dp[flip_index].first > dp[curr].first + 1 || dp[flip_index].first == -1) {
          dp[flip_index] = make_pair(dp[curr].first + 1, dp[curr].second);
          dp_stack.push(flip_index);
        }

        dp[curr].second.first[i] = false;
      }
      for(int i = 0; i < faceDown.size(); i++) {
        bool flipped = dp[curr].second.second[i];
        if(flipped)
          continue;
        dp[curr].second.second[i] = true;
        int flip_index = curr + faceDown[i];
        if(dp[flip_index].first > dp[curr].first + 1 || dp[flip_index].first == -1) {
          dp[flip_index] = make_pair(dp[curr].first + 1, dp[curr].second);
          dp_stack.push(flip_index);
        }

        dp[curr].second.second[i] = false;
      }
    }
    if(dp[goal].first == -1){
		  return {-123456789};
    }
    vector<int> ret;
    for(int i = 0; i < dp[goal].second.first.size(); i++) {
      if(dp[goal].second.first[i]) {
        ret.push_back(-faceUp[i]);
      }
    }
    for(int i = 0; i < dp[goal].second.second.size(); i++) {
      if(dp[goal].second.second[i]) {
        ret.push_back(faceDown[i]);
      }
    }
    return ret;


	}
};
