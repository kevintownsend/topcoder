#include "marauders_map.h"

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
