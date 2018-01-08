#ifndef DEF_CLIENTCTL_H
#define DEF_CLIENTCTL_H

#include "View.h"
#include "ClientNetCtl.h"
#include <thread>

// Has a component ClientNetCtl, View
// This class control the view and net controller
class ClientCtl
{
    public:
        ClientCtl();
        ClientCtl(View* v, ClientNetCtl* cnc);
        ~ClientCtl();
        //Handle the request given by the main function
        void run(char* cmd);

    private:
        ClientNetCtl* net;
        View* view;

};

#endif
