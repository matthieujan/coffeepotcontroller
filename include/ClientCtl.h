#ifndef DEF_CLIENTCTL_H
#define DEF_CLIENTCTL_H

#include "View.h"
#include "ClientNetCtl.h"
#include "PotState.h"
#include <thread>

// Has a component ClientNetCtl, View and PotState

class ClientCtl
{
    public:
        ClientCtl();
        ClientCtl(PotState* ps, View* v, ClientNetCtl* cnc);
        ~ClientCtl();
        void run(char* cmd);

    private:
        ClientNetCtl* net;
        View* view;
        PotState* potstate;

};

#endif
