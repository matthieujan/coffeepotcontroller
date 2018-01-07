#ifndef DEF_SERVERNETCTL_H
#define DEF_SERVERNETCTL_H

#include <boost/asio.hpp>
#include <string>
#include <iostream>

using boost::asio::ip::tcp;
using namespace std;

//Generic Net Controller, store the state of the controller (host and port)
class ServerNetCtl
{
    public:
        ServerNetCtl();
        ServerNetCtl(string host,string port);
        ~ServerNetCtl();

        string getHost();
        string getPort();

        virtual tcp::socket listen()=0;

    private:
        bool running;
        string m_host;
        string m_port;

};


#endif
