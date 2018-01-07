#ifndef DEF_LEDDRIVER_H
#define DEF_LEDDRIVER_H

#include <string>
#include <iostream>
#include <wiringPi.h>
#include <stdio.h>

#include "Driver.h"

using namespace std;

//This driver turn on and off a led wired on the pin 7 of the raspberry
//For testing purpose
class LedDriver : public Driver
{
    public:
        LedDriver();
        ~LedDriver();
        virtual bool get();
        virtual void set(bool value);
    private:
        float m_value;
};
#endif
