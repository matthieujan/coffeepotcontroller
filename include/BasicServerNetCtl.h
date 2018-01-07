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

//This class is the basic implementation of the ServerNetCtl, handling http request
//It act like a very dumb http server (doesnt care about anything but the ?action=XX)
class BasicServerNetCtl : public ServerNetCtl
{
    public:
        BasicServerNetCtl();
        BasicServerNetCtl(string host,string port);
        ~BasicServerNetCtl();

        tcp::socket listen();
        static void session(socket_ptr sock); // Handle a session to a specific client
        static string generateResponse(); // Generate a generic response with potstate values
        static void handleRequest(char* request); // Handle request to know if potstate has to be modified
    private:
        enum { max_length = 4096 };
};


#endif
