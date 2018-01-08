#ifndef DEF_SERVERCTL_H
#define DEF_SERVERCTL_H

#include "PotState.h"
#include "ServerNetCtl.h"
#include "Driver.h"

// Has a component ServerNetCtl, Driver
// This class organise the net and driver object
class ServerCtl
{
    public:
        ServerCtl();
        ServerCtl(ServerNetCtl* net, Driver* d);
        ~ServerCtl();

        void run();

    private:
        ServerNetCtl* net;
        Driver* d;
};

#endif
