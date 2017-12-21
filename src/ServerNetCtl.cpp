#include "ServerNetCtl.h"

ServerNetCtl::ServerNetCtl()
{

}

ServerNetCtl::ServerNetCtl(string host,string port) : m_host(host), m_port(port)
{
    cout << "Parameter : " << port << endl << "Value : " << m_port << endl;
}
ServerNetCtl::~ServerNetCtl()
{

}

string ServerNetCtl::getHost()
{
    return m_host;
}

string ServerNetCtl::getPort()
{
    return m_port;
}
