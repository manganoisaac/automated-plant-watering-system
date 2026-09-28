// Includes
#include "../controller/Controller.h"
#include "StateBase.h"

// Header guard
#ifndef IDLE_H
#define IDLE_H

// Default state the system sits in when nothing needs to happen
class Idle : public StateBase {
public:
  void next(Controller *controller) override;
};
#endif // !IDLE_H
