
class MaraudersMap {
  private:
  int treasureValue;
  int stepCost;
  int numChambers;
  int maxTreasurePickup;

  int pickedupTreasures;

  public:
  MaraudersMap(int treasureValue, int stepCost, int numChambers, int maxTreasurePickup);
  int Step(int treasures);
};

#include <utility>
#include <random>

using namespace std;

class RandomWalk {
  private:
  MaraudersMap map;
  int treasureValue;
  int stepCost;
  int numChambers;
  int maxTreasurePickup;
  default_random_engine generator;
  public:
  RandomWalk(
      int treasureValue, int stepCost, int numChambers, int maxTreasurePickup);
  pair<int, int> Step(int treasures, int paths);
};

#include <algorithm>
#include <random>
#include <iostream>


using namespace std;

RandomWalk::RandomWalk(int treasureValue, int stepCost, int numChambers, int maxTreasurePickup) :
    map(treasureValue, stepCost, numChambers, maxTreasurePickup)
{
  this->treasureValue = treasureValue;
  this->stepCost = stepCost;
  this->numChambers = numChambers;
  this->maxTreasurePickup = maxTreasurePickup;
}

pair<int, int> RandomWalk::Step(int treasures, int paths) {
  int pickup = min(treasures, maxTreasurePickup);
  uniform_int_distribution<int> path_dist(0, paths-1);

  int path = path_dist(generator);
  int expectedTreasures = this->map.Step(pickup);
  cerr << "expectedTreasures:" << expectedTreasures << "\n";
  cerr << "pickup:" << pickup << "\n";
  double expected_value = expectedTreasures * 1.0 * treasureValue / numChambers;
  cerr << "expected_value: " << expected_value << endl;
  cerr << "stepCost:" << stepCost << endl;
  //if (pickup != 0) {
  if (expected_value > stepCost) {
    return make_pair(pickup, path);
  } else {
    return make_pair(-1,-1);
  }
}

MaraudersMap::MaraudersMap(int treasureValue, int stepCost, int numChambers, int maxTreasurePickup) {
    this->treasureValue = treasureValue;
    this->stepCost = stepCost;
    this->numChambers = numChambers;
    this->maxTreasurePickup = maxTreasurePickup;
    this->pickedupTreasures = 0;
}

int MaraudersMap::Step(int treasures){
  this->pickedupTreasures += treasures;
  return numChambers*25 - this->pickedupTreasures;

}
#include <iostream>

using namespace std;

int main() {
	int treasureValue, stepCost, numChambers, maxTreasurePickup;
	cin >> treasureValue >> stepCost >> numChambers >> maxTreasurePickup;
  RandomWalk walker(treasureValue, stepCost, numChambers, maxTreasurePickup);
  for(int i = 0; i < 999; ++i) {
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
