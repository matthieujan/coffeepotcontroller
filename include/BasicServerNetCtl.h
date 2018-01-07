#ifndef DEF_BASICSERVERNETCTL_H
#define DEF_BASICSERVERNETCTL_H

#include "ServerNetCtl.h"
#include "PotState.h"
#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/thread/thread.hpp>

using boost::asio::ip::tcp;
typedef boost::shared_ptr<tcp::socket> socket_ptr;

class BasicServerNetCtl : public ServerNetCtl
{
    public:
        BasicServerNetCtl();
        BasicServerNetCtl(string host,string port);
        ~BasicServerNetCtl();

        tcp::socket listen();
        static void session(socket_ptr sock);
        static string generateResponse();
        static void handleRequest(char* request);
    private:
        enum { max_length = 4096 };
};


#endif
