#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class RerollCheater {
public:
	vector <int> reroll(vector <int> currentDice, vector <int> futureRolls) {
		vector<int> all_dice = futureRolls;
		all_dice.insert(all_dice.end(), currentDice.begin(), currentDice.end());
		sort(all_dice.begin(), all_dice.end());
		int cut_off = all_dice[all_dice.size() - currentDice.size()-1];
		// TODO: find cut off dice.
		vector<int> ret;
		int curr_die = 0;
		for(int i = 0; i < futureRolls.size(); i++) {
			while(currentDice[curr_die] < cut_off) {
				curr_die++;
			}
			if(curr_die >= currentDice.size()) {
				break;
			}
			currentDice[curr_die] = futureRolls[i];
			ret.push_back(curr_die);
		}
		return ret;
	}
};



//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
