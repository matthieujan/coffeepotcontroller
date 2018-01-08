#include "ServerCtl.h"

ServerCtl::ServerCtl()
{

}

ServerCtl::ServerCtl(ServerNetCtl* net,Driver* d)
{
    this->net = net;
    this->d = d;
    PotState::getInstance().setDriver(d);
}

ServerCtl::~ServerCtl()
{
    delete this->net;
    delete this->d;
}

void ServerCtl::run()
{
    this->net->listen();
}
