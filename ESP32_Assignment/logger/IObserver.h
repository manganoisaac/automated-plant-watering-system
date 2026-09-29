//Header guard
#ifndef IOBSERVER_H
#define IOBSERVER_H

//Includes
#include <string>

//Interface for anything event observers
class IObserver {

public:
  virtual void notify(std::string event, std::string data) = 0;
};

#endif // !IOBSERVER_H
