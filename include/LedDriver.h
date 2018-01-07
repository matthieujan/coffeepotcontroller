#ifndef DEF_LEDDRIVER_H
#define DEF_LEDDRIVER_H

#include <string>
#include <iostream>
#include <wiringPi.h>
#include <stdio.h>

#include "Driver.h"

using namespace std;

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
