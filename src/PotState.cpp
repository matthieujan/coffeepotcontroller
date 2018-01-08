#include "PotState.h"

//Getter for state
bool PotState::getState()
{
    return this->state;
}

//Setter for state, call the driver
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

//Set the driver used by PotState
void PotState::setDriver(Driver* d)
{
    this->driver = d;
}
