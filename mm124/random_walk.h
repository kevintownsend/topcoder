#ifndef MM124_RANDOM_WALK_H_
#define MM124_RANDOM_WALK_H_
#include <utility>
#include <random>
#include "marauders_map.h"

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

#endif // MM124_RANDOM_WALK_H_
