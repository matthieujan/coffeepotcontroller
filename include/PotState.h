#ifndef DEF_POTSTATE_H
#define DEF_POTSTATE_H

#include <string>
#include <iostream>
#include "Driver.h"

using namespace std;

/*
 * The PotState object is used by the server to remember what is happening to the coffee pot.
 */
class PotState
{
    public:
        static PotState& getInstance()
        {
            static PotState instance;
            return instance;
        }
        //Deleting the method allowing copies of our PotState
        PotState(PotState const&)               = delete;
        void operator=(PotState const&)  = delete;

        //getter/Setter
        bool getState();
        void setState(bool state);
        long getTime();
        void setTime(long time);
        void setDriver(Driver* driver);

    private:
        PotState() {}
        bool state = false;
        long time = 0;
        Driver* driver;

};

#endif

