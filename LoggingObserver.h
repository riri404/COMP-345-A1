#ifndef LOGGINGOBSERVER_H
#define LOGGINGOBSERVER_H

#include <string>
#include <list>
#include <fstream>

class ILoggable {
public:
  virtual std::string stringToLog() = 0;
};

class Observer {
public:
  virtual void Update(ILoggable*) = 0;
  virtual ~Observer();
  Observer();
};

class Subject {
public:
  virtual void Attach(Observer* o);
  virtual void Detach(Observer* o);
  virtual void Notify(ILoggable*);
  Subject();
  ~Subject();
private:
  std::list<Observer*>* observers;
};

class LogObserver: public Observer {
public:
  ~LogObserver();
  LogObserver();
  void Update(ILoggable*);
private:
  std::ofstream logfile;
};

#endif