#include "LedDriver.h"

LedDriver::LedDriver()
{
    this->m_value = 0;
}

LedDriver::~LedDriver()
{

}

bool LedDriver::get()
{
    return this->m_value;
}

void LedDriver::set(bool value)
{
    int pin = 7;
    pinMode(pin, OUTPUT);

    if(value){
        this->m_value = 1.0;
        digitalWrite(pin, 1);
    }else{
        this->m_value = 0;
        digitalWrite(pin, 0);
    }
}
