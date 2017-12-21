#include "PotState.h"

/*
 *
 */
PotState::PotState()
{
    this->image = "Wala";
    this->on = true;
}

PotState::~PotState()
{

}

bool PotState::isOn()
{
    return this->on;
}


