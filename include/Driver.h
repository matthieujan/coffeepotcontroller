#ifndef DEF_DRIVER_H
#define DEF_DRIVER_H

#include <string>
#include <iostream>

using namespace std;

//Our basic driver, having a get and state and modiying the gpio value accordingly
class Driver
{
    public:
        Driver();
        ~Driver();
        virtual bool get() = 0;
        virtual void set(bool value) = 0;
};
#endif
