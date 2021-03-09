#include "marauders_map.h"

MaraudersMap::MaraudersMap(int treasureValue, int stepCost, int numChambers, int maxTreasurePickup) {
    this->treasureValue = treasureValue;
    this->stepCost = stepCost;
    this->numChambers = numChambers;
    this->maxTreasurePickup = maxTreasurePickup;
}
