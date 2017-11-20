#ifndef DEF_CAMDRIVER_H
#define DEF_CAMDRIVER_H

#include <string>
#include <iostream>
#include <Driver.h>

using namespace std;

class CamDriver : public Driver
{
    public:
        CamDriver();
        ~CamDriver();
        virtual void* get();
        virtual void set();

    protected:
        typedef Driver super;
};
#endif
