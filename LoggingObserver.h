#ifndef LOGGINGOBSERVER_H
#define LOGGINGOBSERVER_H

#include <string>
#include <list>

class ILoggable {
  virtual std::string stringToLog() = 0;
}

class Observer {
public:
  virtual void Update() = 0;
protected:
  Observer();
};

class Subject {
public:
  virtual void Attach(Observer* o);
  virtual void Detach(Observer* o);
  virtual void Notify();
  Subject();
  ~Subject();
private:
  std::list<Observer*> observers;
};

#endif