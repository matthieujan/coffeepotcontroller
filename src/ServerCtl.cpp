#include "ServerCtl.h"

ServerCtl::ServerCtl()
{

}

ServerCtl::ServerCtl(ServerNetCtl* net,CoffeeDriver* cd)
{
    this->net = net;
    this->cd = cd;
}

ServerCtl::~ServerCtl()
{
    delete this->net;
    delete this->cd;
}

void ServerCtl::run()
{
    this->net->listen();
}
