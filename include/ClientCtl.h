#ifndef DEF_CLIENTCTL_H
#define DEF_CLIENTCTL_H

#include "View.h"
#include "ClientNetCtl.h"
#include <thread>

// Has a component ClientNetCtl, View and PotState

class ClientCtl
{
    public:
        ClientCtl();
        ClientCtl(View* v, ClientNetCtl* cnc);
        ~ClientCtl();
        void run(char* cmd);

    private:
        ClientNetCtl* net;
        View* view;

};

#endif
