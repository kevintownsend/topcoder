#include <string>
#include <vector>
#include <deque>

using namespace std;

class SnookerScoring {
	public:
	vector <int> scoreN(int N, int R, int C) {
		if(N <= C + 1) {
      return {N};
    }
    deque<int> ret;

    int sum = 0;
    for(int i = 2; i < 2 + C; i++) {
      if(sum + i - 3 > N) {
        break;
      }
      ret.push_back(i);
      sum += i;
    }
    while((N - sum - 3) > C + 2) {
      ret.push_front(C+1);
      ret.push_front(1);
      sum += C + 2;
    }
    // TODO: push one or two.
    if((N - sum) <= C + 2) {
      ret.push_front(N-sum - 1);
      ret.push_front(1);
    } else {
      ret.push_front(N-sum - 4);
      ret.push_front(1);
      ret.push_front(2);
      ret.push_front(1);
    }

    return vector<int>(ret.begin(), ret.end());
    //return {};
	}
};


// Powered by FileEdit
