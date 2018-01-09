#include "LedDriver.h"

LedDriver::LedDriver()
{
    this->m_value = 0;
}

LedDriver::~LedDriver()
{

}

//Get driver state
bool LedDriver::get()
{
    bool ret;

    //Translating the m_value (float) to ON/OFF format (bool)
    if(m_value == 1.0){
        ret = true;
    }else{
        ret = false;
    }

    return ret;
}

//Set driver state
void LedDriver::set(bool value)
{
    int pin = 7; //RaspberryPi Control Pin
    pinMode(pin, OUTPUT); //Setting the pin to output a signal

    // If value is true, turn on the led
    if(value){
        this->m_value = 1.0;
        digitalWrite(pin, 1);
    }
    // Else, turn off the led
    else{
        this->m_value = 0;
        digitalWrite(pin, 0);
    }
}
