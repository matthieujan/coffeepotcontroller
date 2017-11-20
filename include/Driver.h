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
        virtual void* get() = 0;
        virtual void set() = 0;
};
#endif
