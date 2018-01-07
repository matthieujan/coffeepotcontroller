#include "PotState.h"

bool PotState::getState()
{
    return this->state;
}

void PotState::setState(bool value)
{
    this->driver->set(value);
    this->state = value;
}

long PotState::getTime()
{
    return this->time;
}

void PotState::setTime(long t)
{
    this->time = t;
}

void PotState::setDriver(Driver* d)
{
    this->driver = d;
}
