#ifndef DEF_SERVERCTL_H
#define DEF_SERVERCTL_H

#include "PotState.h"
#include "ServerNetCtl.h"
#include "CoffeeDriver.h"

// Has a component PotState, ServerNetCtl, CamDriver and CoffeeDriver

class ServerCtl
{
    public:
        ServerCtl();
        ServerCtl(ServerNetCtl* net, CoffeeDriver* cd);
        ~ServerCtl();

        void run();

    private:
        ServerNetCtl* net;
        CoffeeDriver* cd;
};

#endif
