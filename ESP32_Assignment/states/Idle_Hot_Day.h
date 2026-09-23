#include "../controller/Controller.h"
#include "IState.h"
#include "StateBase.h"
#ifndef IDLE_HOT_DAY_H
#define IDLE_HOT_DAY_H
class IdleHotDay : public StateBase {
public:
  void next(Controller *controller) override;
};
#endif // !IDLE_HOT_DAY_H
