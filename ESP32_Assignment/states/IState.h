//Header guard
#ifndef ISTATE_H
#define ISTATE_H

//Tells the compiler Controller exists, without needing its full header here
class Controller;

//Interface every state must implement
class IState {
public:
  virtual void next(Controller *controller) = 0;
};
#endif // !ISTATE_H
