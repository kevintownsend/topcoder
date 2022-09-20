// BEGIN CUT HERE

// END CUT HERE
//#line 5 "CastleGuard.cc"
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class CastleGuard {
	public:
	vector<long long> walk(int N, int R, vector <int> commands) {
    vector<int64_t> ret;
    vector<int64_t> lap;
    int location = 0;
    for(int i = 0; i < commands.size(); i++) {
      // TODO: mod math.
      location = ((location + commands[i]) % N + N) % N;
      int64_t loops = commands[i] / N;
      if (commands[i] >= 0) {
        int64_t remainder = commands[i] - loops * N;
        for(int j = 0; j < remainder; j++) {
          location = (location + 1) % N;
          lap[location]++;
        }
      } else {
        int64_t remainder = commands[i] + loops * N;
      }
        
        //ret[loctai

    }


		// TODO: add 1 to 0.
	}
};
