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
/*
 * This method emit a command to the server
 */
void BasicClientNetCtl::emitCmd(string req)
{
    try
    {
        //Resolve remote host
        boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), this->getHost(), this->getPort());
        tcp::resolver::iterator iterator = resolver.resolve(query);

        //Socket definition and connection
        tcp::socket s(io_service);
        boost::asio::connect(s, iterator);

        //Request sending
        using namespace std;
        char request[max_length];
        strcpy(request,req.c_str());
        size_t request_length = strlen(request);
        boost::asio::write(s, boost::asio::buffer(request, request_length));

        //Response handling
        char reply[max_length];
        boost::system::error_code error;
        size_t reply_length = boost::asio::read(s,
            boost::asio::buffer(reply),error);
        this->handleReply(reply);
    }
    catch (std::exception& e)
    {
        //Basic exception handling, generate an error feedback to the user
        std::cerr << "Exception: " << e.what() << "\n";
    }
}

/*
 * This method handle the reply sent from the server
 */
void BasicClientNetCtl::handleReply(char* rep)
{
    string reply = rep;

    //It basically search a specific string in the reply to define the coffee pot state
    if(reply.find("cafetière est actuellement en marche") != string::npos){
        cout << "CoffeePot On" << endl;
    }else if(reply.find("cafetière est actuellement éteinte") != string::npos){
        cout << "CoffeePot Off" << endl;
    }

}
