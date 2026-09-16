#ifndef ISTATE_H
#define ISTATE_H

class Controller;

class IState {
public:
  virtual void next(Controller *controller) = 0;
};
#endif // !ISTATE_H
