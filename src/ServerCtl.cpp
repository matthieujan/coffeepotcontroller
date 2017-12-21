#include "ServerCtl.h"

ServerCtl::ServerCtl()
{

}

ServerCtl::ServerCtl(PotState* potstate, ServerNetCtl* net,CoffeeDriver* cd)
{
    this->net = net;
    this->cd = cd;
    this->potstate = potstate;
}

ServerCtl::~ServerCtl()
{
    delete this->net;
    delete this->cd;
    delete this->potstate;
}

void ServerCtl::run()
{
    this->net->listen();
}
