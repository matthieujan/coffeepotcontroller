#ifndef DEF_LEDDRIVER_H
#define DEF_LEDDRIVER_H

#include <string>
#include <iostream>
#include "Driver.h"

using namespace std;

class LedDriver : public Driver
{
    public:
        LedDriver();
        ~LedDriver();
        virtual float get();
        virtual void set(float value);
    private:
        float m_value;
};
#endif
