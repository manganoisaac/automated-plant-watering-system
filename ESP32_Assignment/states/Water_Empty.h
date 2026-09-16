#ifndef WATER_EMPTY_H
#define WATER_EMPTY_H

#include "../controller/Controller.h"
class WaterEmpty : public IState {
public:
  void next(Controller *controller) override;
};

#endif // !WATER_EMPTY_H
