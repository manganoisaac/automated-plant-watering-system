//Header guard
#ifndef WATER_EMPTY_H
#define WATER_EMPTY_H

//Includes
#include "../controller/Controller.h"
#include "StateBase.h"

//state entered when the water tank is empty
class WaterEmpty : public StateBase {
public:
  void next(Controller *controller) override;
};

#endif // !WATER_EMPTY_H
