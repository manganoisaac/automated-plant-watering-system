#include "../controller/Controller.h"
#include "IState.h"
#ifndef IDLE_H
#define IDLE_H
class Idle : public IState {
public:
  void next(Controller *controller) override;
};
#endif // !IDLE_H
