#include "ClientCtl.h"

ClientCtl::ClientCtl()
{

}

ClientCtl::ClientCtl(PotState* potstate, View* view, ClientNetCtl* net)
{
    this->net = net;
    this->view = view;
    this->potstate = potstate;
}

ClientCtl::~ClientCtl()
{
    delete this->net;
    delete this->view;
    delete this->potstate;
}

void ClientCtl::run()
{
    bool running = true;
    while(running)
    {
        string input = this->view->ask();
        string message = "Error";
        if(input == "start"){
            this->net->startCpc();
        }else if(input == "stop"){
            this->net->stopCpc();
        }else if(input == "exit"){
            cout << "Bye" << endl;
            running = false;
        }else if(input == "get"){
            this->net->getCpc();
        }else{
            cout << "Not a valid command : type exit to exit" << endl;
        }
    }
}
