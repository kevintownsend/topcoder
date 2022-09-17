// BEGIN CUT HERE

// END CUT HERE
#line 5 "DoubleWordLadder.cc"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class DoubleWordLadder {
	public:
	vector <string> transform(string A, string B) {
		int letters_diff = 0;
    int last_diff = -1;
    for (int i = 0; i < A.size(); i++) {
      if(A[i] != B[i]) {
        letters_diff++;
        last_diff = i;
      }
    }
    cerr << "letters_diff: " << letters_diff << endl;
    if(letters_diff == 0) {
      return {A};
    }
    if(letters_diff == 1) {
      int tmp_i = 0;
      if(last_diff == 0)
        tmp_i = 1;
      vector<string> ret;
      ret.push_back(A);
      A[last_diff] = new_char(A[last_diff], B[last_diff]);
      ret.push_back(A);
      A[tmp_i] = new_char(A[tmp_i],A[tmp_i]);
      ret.push_back(A);
      A[last_diff] = B[last_diff];
      ret.push_back(A);
      ret.push_back(B);
      return ret;

    }
    vector<string> ret;
    for(int i = 0; i < A.size(); i++) {
      if (A[i] != B[i]) {
        A[i] = new_char(A[i], B[i]);
        ret.push_back(A);
      }
    }
    for(int i = 0; i < A.size(); i++) {
      if (A[i] != B[i]) {
        A[i] = B[i];
        ret.push_back(A);
      }
    }
    return ret;
	}

  char new_char(char a, char b) {
    if (a != 'a' && b != 'a')
      return 'a';
    if (a != 'b' && b != 'b')
      return 'b';
    if (a != 'c' && b != 'c')
      return 'c';
    return 'z';
  }
};
