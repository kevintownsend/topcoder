#include "random_walk.h"
#include <iostream>

using namespace std;

int main() {
	int treasureValue, stepCost, numChambers, maxTreasurePickup;
	cin >> treasureValue >> stepCost >> numChambers >> maxTreasurePickup;
  RandomWalk walker(treasureValue, stepCost, numChambers, maxTreasurePickup);
  for(int i = 0; i < 0; ++i) {
    cerr << "step: " << i << "\n";
		int treasureCount, pathCount;
		string time;
		cin >> treasureCount >> pathCount >> time;
    pair<int, int> ret = walker.Step(treasureCount, pathCount);
    cout << ret.first << "\n";
    cout << ret.second << "\n";
		fflush(stdout);
  }
  cout << "-1" << endl;
  cout << "-1" << endl;
}
