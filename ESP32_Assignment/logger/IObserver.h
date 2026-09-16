#ifndef IOBSERVER_H

#define IOBSERVER_H

#include <string>
class IObserver {

public:
  virtual void notify(std::string event, std::string data) = 0;
};

#endif // !IOBSERVER_H
