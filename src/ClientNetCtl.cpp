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

//Host getter
string ClientNetCtl::getHost()
{
    return m_host;
}

//Port getter
string ClientNetCtl::getPort()
{
    return m_port;
}
