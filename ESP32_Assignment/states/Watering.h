
#include "../controller/Controller.h"
#include "IState.h"
#include "StateBase.h"
#ifndef WATERING_H
#define WATERING_H
class Watering : public StateBase {
public:
  void next(Controller *controller) override;
};
#endif // !WATERING_H
