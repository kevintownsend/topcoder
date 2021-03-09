#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

class LostTreasureHunter {
	int treasureValue, stepCost, numChambers, maxTreasure;
	int numStep;
public :
	void init(int treasureValue, int stepCost, int numChambers, int maxTreasure) {
		this->treasureValue = treasureValue;
		this->stepCost = stepCost;
		this->numChambers = numChambers;
		this->maxTreasure = maxTreasure;
		this->numStep = 0;
	}

	vector<int> findSolution(int treasureCount, int pathCount, string time) {
		vector<int> res(2,-1);

		if(this->numStep >= 1) return res;
		this->numStep += 1;

		res[0] = min(treasureCount, maxTreasure);
		res[1] = pathCount - 1;

		return res;
	}
};

int main() {
	int treasureValue, stepCost, numChambers, maxTreasure;
	cin >> treasureValue >> stepCost >> numChambers >> maxTreasure;

	LostTreasureHunter o;
	o.init(treasureValue, stepCost, numChambers, maxTreasure);

	for(;;) {
		int treasureCount, pathCount;
		cin >> treasureCount >> pathCount;
		string time;
		cin >> time;

		vector<int> res = o.findSolution(treasureCount, pathCount, time);

		cout << res[0] << endl;
		if(res[0]>-1) cout << res[1] << endl;
		fflush(stdout);
	}
}

