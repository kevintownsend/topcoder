#include <algorithm>
#include <random>
#include <iostream>

#include "random_walk.h"
#include "marauders_map.h"

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
