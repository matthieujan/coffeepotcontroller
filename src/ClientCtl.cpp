#include "ClientCtl.h"

ClientCtl::ClientCtl()
{

}

ClientCtl::ClientCtl(View* view, ClientNetCtl* net)
{
    this->net = net;
    this->view = view;
}

ClientCtl::~ClientCtl()
{
    delete this->net;
    delete this->view;
}

/*
 * Method to run the client
 */
void ClientCtl::run(char* cmd)
{
    string input = cmd;
    if(input == "start"){
        this->net->emitCmd("GET /?action=on");
    }else if(input == "stop"){
        this->net->emitCmd("GET /?action=off");
    }else if(input == "get"){
        this->net->emitCmd("GET /");
    }else{
        cout << "Not a valid command : use start, stop or get" << endl;
    }
}
