
#include "../controller/Controller.h"
#include "IState.h"
#ifndef WATERING_H
#define WATERING_H
class Watering : public IState {
public:
  void next(Controller *controller) override;
};
#endif // !WATERING_H
