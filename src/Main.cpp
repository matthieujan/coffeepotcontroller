#include <iostream>
#include <string.h>
#include "ServerCtl.h"
#include "ClientCtl.h"
#include "BasicClientNetCtl.h"
#include "ConsoleView.h"
#include "PotState.h"
using namespace std;

int server(){
    cout << "Starting server :" << endl;
    ServerCtl* sc = new ServerCtl();
    return 0;
}

int bvbnclient(char* argv[]){
    cout << "Starting client :" << endl;
    View* v = new ConsoleView();
    PotState* ps = new PotState();
    //TODO correct host
    ClientNetCtl* cnc = new BasicClientNetCtl(argv[2],argv[3]);
    cout << cnc->getHost() << endl;
    cout << cnc->getPort() << endl;
    ClientCtl* sc = new ClientCtl(ps,v,cnc);
    sc->run();
    return 0;
}

int main(int argc, char *argv[]){

    if(strcmp (argv[1],"server") == 0){
        server();
    }
    if(strcmp (argv[1],"bvbnclient") == 0){
        bvbnclient(argv);
    }
    return 0;
}
