#include "PotState.h"

bool PotState::getState()
{
    return this->state;
}

void PotState::setState(bool value)
{
    this->state = value;
}

