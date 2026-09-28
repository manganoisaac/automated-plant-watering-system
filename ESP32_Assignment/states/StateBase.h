//Header guard
#ifndef STATE_BASE_H
#define STATE_BASE_H

//Includes
#include "IState.h"

//Shared base class for all states, holds the functions used to switch state
class StateBase : public IState {
protected:
  void to_error(Controller *controller);
  void to_idle(Controller *controller);
  void to_idle_hot_day(Controller *controller);
  void to_watering(Controller *controller);
  void to_water_empty(Controller *controller);
  void sleep(int millis);
};

#endif // !STATE_BASE_H
