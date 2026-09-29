//Header guard
#ifndef ERROR_H
#define ERROR_H

//Includes
#include "IState.h"
#include "StateBase.h"

//State entered when a fault is detected
class Error : public StateBase {
public:
  void next(Controller *controller) override;
};

#endif // !ERROR_H
