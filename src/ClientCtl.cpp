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

void ClientCtl::run(char* cmd)
{
    bool running = true;
    while(running)
    {
        string input = cmd;
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
