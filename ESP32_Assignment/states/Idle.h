#include "../controller/Controller.h"
#include "StateBase.h"
#ifndef IDLE_H
#define IDLE_H
class Idle : public StateBase {
public:
  void next(Controller *controller) override;
};
#endif // !IDLE_H
