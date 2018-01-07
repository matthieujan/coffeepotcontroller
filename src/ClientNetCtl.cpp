#include "ClientNetCtl.h"

ClientNetCtl::ClientNetCtl()
{

}

ClientNetCtl::ClientNetCtl(string host,string port) : m_host(host), m_port(port)
{
}
ClientNetCtl::~ClientNetCtl()
{

}

string ClientNetCtl::getHost()
{
    return m_host;
}

string ClientNetCtl::getPort()
{
    return m_port;
}
