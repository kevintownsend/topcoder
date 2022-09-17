// BEGIN CUT HERE

// END CUT HERE
#line 5 "SortTwoArrays.cc"
#include <string>
#include <vector>

using namespace std;

class SortTwoArrays {


	public:
    vector <int> twoSorts(int N, vector <int> A, vector <int> B) {
      int ai = 0;
      int bi = 0;
      vector<int> ret;
      // TODO: loop.
      while (ai != N - 1 && bi != N - 1) {
        bool min_in_a = 1;
        int min = 1000;
        int min_index = -1;
        for(int i = ai; i < N; i++) {
          if (A[i] < min) {
            min = A[i];
            min_index = i;
          }
        }
        for(int i = bi; i < N; i++) {
          if (B[i] < min) {
            min_in_a = 0;
            min = B[i];
            min_index = i;
          }
        }
        int swap;
        if (min_in_a) {
          if (bi == N - 1) {
            if (min_index != ai) {
              ret.push_back(min_index);
              ret.push_back(N-1);
              ret.push_back(ai);
              ret.push_back(N-1);
              A[min_index] = B[N-1];
              B[N-1] = A[ai];
            }
            ai++;
          }
          swap = B[bi];
          B[bi] = min;
          A[min_index] = swap;
          ret.push_back(min_index);
          ret.push_back(bi);
          bi++;
        } else {
          if (ai == N - 1) {
            if (min_index != bi) {
              ret.push_back(min_index);
              ret.push_back(N-1);
              ret.push_back(bi);
              ret.push_back(N-1);
              B[min_index] = A[N-1];
              A[N-1] = B[bi];
            }
            ai++;
          }
          swap = A[ai];
          A[ai] = min;
          B[min_index] = swap;
          ret.push_back(ai);
          ret.push_back(min_index);
          ai++;
        }
      }


      return ret;
	  }
};
