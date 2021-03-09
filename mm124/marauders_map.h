#ifndef MM124_MARAUDERS_MAP_H_
#define MM124_MARAUDERS_MAP_H_

class MaraudersMap {
  private:
  int treasureValue;
  int stepCost;
  int numChambers;
  int maxTreasurePickup;

  int pickedupTreasures;

  public:
  MaraudersMap(int treasureValue, int stepCost, int numChambers, int maxTreasurePickup);
};

#endif
