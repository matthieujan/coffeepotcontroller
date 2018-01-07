#ifndef DEF_DRIVER_H
#define DEF_DRIVER_H

#include <string>
#include <iostream>

using namespace std;

class Driver
{
    public:
        Driver();
        ~Driver();
        virtual float get() = 0;
        virtual void set(float value) = 0;
};
#endif
