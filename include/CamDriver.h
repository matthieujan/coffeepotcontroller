#ifndef DEF_CAMDRIVER_H
#define DEF_CAMDRIVER_H

#include <string>
#include <iostream>

using namespace std;

class CamDriver
{
    public:
        CamDriver();
        ~CamDriver();
        bool turnOn();
        bool turnOff();
        bool snapshot();
};
#endif
