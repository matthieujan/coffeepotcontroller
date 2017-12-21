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

void BasicClientNetCtl::startCpc()
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
        char request[max_length] = "start";
        size_t request_length = strlen(request);
        boost::asio::write(s, boost::asio::buffer(request, request_length));

        char reply[max_length];
        size_t reply_length = boost::asio::read(s,
            boost::asio::buffer(reply, request_length));
        //TODO Handle Response
        std::cout << "Reply is: ";
        std::cout.write(reply, reply_length);
        std::cout << "\n";
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}

void BasicClientNetCtl::stopCpc()
{
    try
    {
        boost::asio::io_service io_service;

        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), this->getHost(), this->getPort());
        tcp::resolver::iterator iterator = resolver.resolve(query);

        tcp::socket s(io_service);
        boost::asio::connect(s, iterator);

        using namespace std; // for strlen.
        char request[max_length] = "stop";
        size_t request_length = strlen(request);
        boost::asio::write(s, boost::asio::buffer(request, request_length));

        char reply[max_length];
        size_t reply_length = boost::asio::read(s,
            boost::asio::buffer(reply, request_length));
        //todo handle response
        std::cout << "reply is: ";
        std::cout.write(reply, reply_length);
        std::cout << "\n";
    }
    catch (std::exception& e)
    {
        std::cerr << "exception: " << e.what() << "\n";
    }
    cout << "/start cpc" << endl;

}

void BasicClientNetCtl::getCpc()
{
    try
    {
        boost::asio::io_service io_service;

        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), this->getHost(), this->getPort());
        tcp::resolver::iterator iterator = resolver.resolve(query);

        tcp::socket s(io_service);
        boost::asio::connect(s, iterator);

        using namespace std; // for strlen.
        char request[max_length] = "Enculé !";
        size_t request_length = strlen(request);
        boost::asio::write(s, boost::asio::buffer(request, request_length));

        char reply[max_length];
        size_t reply_length = boost::asio::read(s,
            boost::asio::buffer(reply, request_length));
        //todo handle response
        std::cout << "reply is: ";
        std::cout.write(reply, reply_length);
        std::cout << "\n";
    }
    catch (std::exception& e)
    {
        std::cerr << "exception: " << e.what() << "\n";
    }
    cout << "/start cpc" << endl;
}

