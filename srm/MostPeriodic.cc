// BEGIN CUT HERE

// END CUT HERE
#line 5 "MostPeriodic.cc"
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

class MostPeriodic {
	public:
  string construct(string bank) {
    // TODO: sort.
    sort(bank.begin(), bank.end());
    // TODO: map frequency.
    map<char, int> frequency;
    int N = bank.size();
    for(int i = 0; i < N; i++) {
      frequency[bank[i]]++; // fix
    }

    int iterations = INT_MAX;
    for(auto it = frequency.begin(); it != frequency.end(); it++) {
      if(it->second < iterations) {
        iterations = it->second;
      }
    }
    iterations++;
    // TODO: left and right string.
    vector<char> left;
    vector<char> right;
    for(auto it = frequency.begin(); it != frequency.end(); it++) {
      int left_add = it->second / iterations;
      int right_add = iterations - (it->second % iterations);
      for(int i = 0; i < left_add; i++) {
        left.push_back(it->first);
      }
      for(int i = 0; i < right_add; i++) {
        right.push_back(it->first);
      }
    }

    // TODO: create final string.
    vector<int> ret;
    for(int i = 0; i < iterations - 1; i++) {
      ret.insert(ret.end(), left.begin(), left.end());
      ret.insert(ret.end(), right.begin(), right.end());
    }
    ret.insert(ret.end(), left.begin(), left.end());
    return string(ret.begin(), ret.end());
  }
};

