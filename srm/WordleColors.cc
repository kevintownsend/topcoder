// BEGIN CUT HERE

// END CUT HERE
#line 5 "WordleColors.cc"
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class WordleColors {
	public:
	string color(string hidden, string guess) {
		vector<char> ret;
    set<char> has_letter;
    map<char, int> letter_count;
    for(int i = 0; i < 5; i++) {
      has_letter.insert(hidden[i]);
      if(hidden[i] != guess[i])
        letter_count[hidden[i]]++;
    }
    map<char, int> running_letter_count;
    for(int i = 0; i < 5; i++) {
      if(hidden[i] != guess[i])
        running_letter_count[guess[i]]++;
      if(hidden[i] == guess[i]) {
        ret.push_back('g');
      } else if(has_letter.find(guess[i]) != has_letter.end() && running_letter_count[guess[i]]<= letter_count[guess[i]]) {
        ret.push_back('y');
      } else {
        ret.push_back('-');
      }
    }
    return string(ret.begin(), ret.end());
	}
};
