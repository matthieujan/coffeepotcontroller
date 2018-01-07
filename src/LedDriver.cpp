#include "LedDriver.h"

LedDriver::LedDriver()
{
    this->m_value = 0;
}

LedDriver::~LedDriver()
{

}

float LedDriver::get()
{
    return this->m_value;
}

void LedDriver::set(float value)
{
    this->m_value = value;
}
