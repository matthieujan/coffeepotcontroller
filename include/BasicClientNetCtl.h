#ifndef DEF_BASICCLIENTNETCTL_H
#define DEF_BASICCLIENTNETCTL_H

#include "ClientNetCtl.h"
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class BasicClientNetCtl : public ClientNetCtl
{
    public:
        BasicClientNetCtl();
        BasicClientNetCtl(string host,string port);
        ~BasicClientNetCtl();

        void emitCmd(string request);
        void handleReply(char* reply);
    private:
        enum { max_length = 4096 };
};


#endif
