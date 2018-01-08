#include "PotState.h"

bool PotState::getState()
{
    return this->state;
}

void PotState::setState(bool value)
{
    this->driver->set(value);
    this->state = value;
    if(value)
    {
      this->timer = time(NULL);
    }
}

time_t PotState::getTime()
{
    return this->timer;
}

void PotState::setTime(time_t t)
{
    this->timer = t;
}

string PotState::getDate(){
  return this->date;
}

void PotState::setDate()
{
  time_t temps;
  struct tm datetime;
  char  format[32];
  time(&temps);
  datetime = *localtime(&temps);
  strftime(format, 32, "%Y-%m-%d %H-%M", &datetime);

  this->date = format;
}

void PotState::setDriver(Driver* d)
{
    this->driver = d;
}

int PotState::timePassed()
{
  return (int) (time(NULL) - this->timer);
}
