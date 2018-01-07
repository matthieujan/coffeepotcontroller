#include <iostream>
#include <string.h>
#include "ServerCtl.h"
#include "ClientCtl.h"
#include "BasicClientNetCtl.h"
#include "BasicServerNetCtl.h"
#include "ConsoleView.h"
#include "LedDriver.h"
#include "PotState.h"
using namespace std;

int server(char* argv[]){
    cout << "Starting server :" << endl;
    ServerNetCtl* snc= new BasicServerNetCtl(argv[2],argv[3]);
    Driver * cd = new LedDriver();
    ServerCtl* sc = new ServerCtl(snc,cd);
    sc->run();
    return 0;
}

int bvbnclient(char* argv[]){
    cout << "Starting client :" << endl;
    View* v = new ConsoleView();
    //TODO correct host
    ClientNetCtl* cnc = new BasicClientNetCtl(argv[2],argv[3]);
    ClientCtl* sc = new ClientCtl(v,cnc);
    sc->run(argv[4]);
    return 0;
}

int main(int argc, char *argv[]){

    if(strcmp (argv[1],"server") == 0){
        server(argv);
    }
    if(strcmp (argv[1],"bvbnclient") == 0){
        bvbnclient(argv);
    }
    return 0;
}
