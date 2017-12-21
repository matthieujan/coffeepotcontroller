#ifndef DEF_CLIENTNETCTL_H
#define DEF_CLIENTNETCTL_H

#include <string>
#include <iostream>
#include <boost/asio.hpp>

using namespace std;
using boost::asio::ip::tcp;

class ClientNetCtl
{
    public:
        ClientNetCtl();
        ClientNetCtl(string host,string port);
        ~ClientNetCtl();

        string test();

        string getHost();
        string getPort();

        virtual void startCpc() = 0;
        virtual void stopCpc() = 0;
        virtual void getCpc() = 0;

    private:
        bool running;
        string m_host;
        string m_port;
};


#endif
