#ifndef ERROR_H
#define ERROR_H

#include "IState.h"
#include "StateBase.h"
class Error : public StateBase {
public:
  void next(Controller *controller) override;
};

#endif // !ERROR_H
