// BEGIN CUT HERE

// END CUT HERE
#line 5 "HashingWithBackupTapes.cc"
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class HashingWithBackupTapes {
	public:
	long long optimize(int H, int T, int N, int L, vector <int> W, int seed) {
		vector<int> who;
    for(int i = 0; i < H; i++) {
      for(int j = 0; j < W[i]; j++) {
        who.push_back(i);
      }
    }
    int state = seed;
    vector<int> bkt;
    vector<int> cnt;
    map<int, int> buckets;
    for(int i = 0; i < N; i++) {
      state = (state * 1103515245LL + 12345LL) % 1LL<<31;
      bkt.push_back(who[state % who.size()]);
      state = (state * 1103515245LL + 12345LL) % 1LL<<31;
      cnt.push_back(1 + (state % L));
      buckets[bkt[i]]+= cnt[i];
    }
    // TODO: for 0 to H
    for(int i = 0; i < H; i++) {
      //set<pair<
      map<double, tuple<int, int, int> > chunk_size_to_bucket_cnt_backups;
      int j = 0;
      uint64_t cost = 0;
      for(auto it = buckets.rbegin(); it != buckets.rend(); it++) {
        if(j < i) {
          chunk_size_to_bucket_cnt_backups[it->second] = make_tuple(it->first, it->second, 0);
        } else {
          cost += (it->second) * (it->second - 1LL) / 2;
        }
        j++;
      }
      for(int j = 0; j < T; j++) {
        auto val = chunk_size_to_bucket_cnt_backups.rend()->second;
        get<2>(val)++;
        // TODO: complete.
        int new_backups = get<2>(last_it->second) + 1;
        chunk_size_to_bucket_cnt_backups[get<1>(last_it*) * 1.0L / get<2>(last_it*)] = make_tuple(get<0>(last_it*), get<1>(last_it*), get<2>(*last_it) + 1);
        chunk_size_to_bucket_cnt_backups.erase(chunk_size_to_bucket_cnt_backups.end()--);
      }

    }
    // TODO: running calculation
    // TODO: for 0 to T 
    return 0;
	}
};
