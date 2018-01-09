#ifndef DEF_COFFEEDRIVER_H
#define DEF_COFFEEDRIVER_H

#include <string>
#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <Python.h>
#include <stdio.h>

#include "Driver.h"

using namespace std;

//This driver turn on and off a led wired on the pin 7 of the raspberry
//For testing purpose
class CoffeeDriver : public Driver
{
    public:
        CoffeeDriver();
        ~CoffeeDriver();
        virtual bool get();
        virtual void set(bool value);
    private:
        float m_value;
};
#endif
