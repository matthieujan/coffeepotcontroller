#ifndef DEF_POTSTATE_H
#define DEF_POTSTATE_H

#include <string>
#include <iostream>
#include <time.h>
#include <ctime>
#include "Driver.h"

using namespace std;

/*
 * The PotState object is used by the server to remember what is happening to the coffee pot.
 * It use his driver to modify the state physically
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
        time_t getTime();
        void setTime(time_t time);
        string getDate();
        void setDate();
        void setDriver(Driver* driver);
        int timePassed();


    private:
        PotState() {}
        bool state = false;
        time_t timer;
        Driver* driver;
        string date;
};

#endif
