#ifndef DEF_SERVERCTL_H
#define DEF_SERVERCTL_H

#include "PotState.h"
#include "ServerNetCtl.h"
#include "Driver.h"

// Has a component PotState, ServerNetCtl, CamDriver and CoffeeDriver

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
