#ifndef DEF_BASICCLIENTNETCTL_H
#define DEF_BASICCLIENTNETCTL_H

#include "ClientNetCtl.h"
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

/*
 * This object serve has our net controller to communication with the server.
 * Act to be understand by our very dumb server (transmit only GET /?action=XX)
 */
class BasicClientNetCtl : public ClientNetCtl
{
    public:
        BasicClientNetCtl();
        BasicClientNetCtl(string host,string port);
        ~BasicClientNetCtl();

        // Emit a (valid) command to the server
        void emitCmd(string request);
        // Handle the response to know if the coffee pot is on or off
        void handleReply(char* reply);
    private:
        // Max size of the buffer we use
        enum { max_length = 4096 };
};


#endif
