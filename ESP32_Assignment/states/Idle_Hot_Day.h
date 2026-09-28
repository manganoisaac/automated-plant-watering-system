// Includes
#include "../controller/Controller.h"
#include "IState.h"
#include "StateBase.h"

// Header guard
#ifndef IDLE_HOT_DAY_H
#define IDLE_HOT_DAY_H

// Idle state used on hot days, same as Idle but also watches for it cooling down
class IdleHotDay : public StateBase {
public:
  void next(Controller *controller) override;
};
#endif // !IDLE_HOT_DAY_H
