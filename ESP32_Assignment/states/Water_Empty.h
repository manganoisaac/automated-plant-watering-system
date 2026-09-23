#ifndef WATER_EMPTY_H
#define WATER_EMPTY_H

#include "../controller/Controller.h"
#include "StateBase.h"
class WaterEmpty : public StateBase {
public:
  void next(Controller *controller) override;
};

#endif // !WATER_EMPTY_H
