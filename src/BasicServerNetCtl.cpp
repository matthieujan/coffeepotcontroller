#include "BasicServerNetCtl.h"

BasicServerNetCtl::BasicServerNetCtl()
{

}

BasicServerNetCtl::BasicServerNetCtl(string host,string port) : ServerNetCtl(host,port)
{

}

BasicServerNetCtl::~BasicServerNetCtl()
{

}

tcp::socket BasicServerNetCtl::listen()
{
    boost::asio::io_service io_service;

    tcp::acceptor a(io_service, tcp::endpoint(tcp::v4(), stoi(this->getPort())));
    for (;;)
    {
        socket_ptr sock(new tcp::socket(io_service));
        a.accept(*sock);
        boost::thread t(boost::bind(session, sock));
    }

}

void BasicServerNetCtl::session(socket_ptr sock)
{
  try
  {
      char data[max_length];
      boost::system::error_code error;
      size_t length = sock->read_some(boost::asio::buffer(data), error);

      boost::asio::write(*sock, boost::asio::buffer(data, length));
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception in thread: " << e.what() << "\n";
  }
}



