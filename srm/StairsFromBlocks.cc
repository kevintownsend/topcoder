// BEGIN CUT HERE

// END CUT HERE
#line 5 "StairsFromBlocks.cc"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class StairsFromBlocks {
	public:
	long long build(vector <int> W, vector <int> H) {
		uint64_t volume_of_blocks = 0;
    vector<pair<int, int> > blocks;
    for(int i = 0; i < W.size(); i++) {
      volume_of_blocks += W[i] * 1.0L * H[i];
      blocks.emplace_back(H[i], W[i]);
    }
    sort(blocks.begin(), blocks.end(), [](pair<int, int> a, pair<int, int> b) {return a.first < b.first;});
    uint64_t width = 0;
    for(int i = 0; i < blocks.size(); i++) {
      if(blocks[i].first > width) {
        width = blocks[i].first;
      }
      width += blocks[i].second;
    }
    return ((width - 1L)*(width) / 2L - volume_of_blocks);
	}
};
