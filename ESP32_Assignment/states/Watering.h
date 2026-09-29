
//Includes
#include "../controller/Controller.h"
#include "IState.h"
#include "StateBase.h"

//Header guard
#ifndef WATERING_H
#define WATERING_H

//State entered while the pump is running
class Watering : public StateBase {
public:
  void next(Controller *controller) override;
};
#endif // !WATERING_H
