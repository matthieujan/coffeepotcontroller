#include "BasicClientNetCtl.h"

BasicClientNetCtl::BasicClientNetCtl()
{

}

BasicClientNetCtl::BasicClientNetCtl(string host,string port) : ClientNetCtl(host,port)
{
}

BasicClientNetCtl::~BasicClientNetCtl()
{

}

void BasicClientNetCtl::emitCmd(string req)
{
    try
    {
        boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), this->getHost(), this->getPort());
        tcp::resolver::iterator iterator = resolver.resolve(query);

        tcp::socket s(io_service);
        boost::asio::connect(s, iterator);

        using namespace std; // For strlen.
        char request[max_length];
        strcpy(request,req.c_str());
        size_t request_length = strlen(request);
        boost::asio::write(s, boost::asio::buffer(request, request_length));

        char reply[max_length];
        boost::system::error_code error;
        size_t reply_length = boost::asio::read(s,
            boost::asio::buffer(reply),error);
        this->handleReply(reply);
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}

void BasicClientNetCtl::handleReply(char* rep)
{
    string reply = rep;

    if(reply.find("cafetière est actuellement en marche") != string::npos){
        cout << "CoffeePot On" << endl;
    }else if(reply.find("cafetière est actuellement éteinte") != string::npos){
        cout << "CoffeePot Off" << endl;
    }

}
