#ifndef DEF_CLIENTNETCTL_H
#define DEF_CLIENTNETCTL_H

#include <string>
#include <iostream>
#include <boost/asio.hpp>

using namespace std;
using boost::asio::ip::tcp;

// Generic NetCtl for the client
// Store the host and port information, and a virtual emitCmd
class ClientNetCtl
{
    public:
        ClientNetCtl();
        ClientNetCtl(string host,string port);
        ~ClientNetCtl();

        string test();

        string getHost();
        string getPort();

        virtual void emitCmd(string cmd) = 0;

    private:
        string m_host;
        string m_port;
};


#endif
