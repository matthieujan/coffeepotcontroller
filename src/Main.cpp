#include <iostream>
#include <string.h>
#include "ServerCtl.h"
#include "ClientCtl.h"
#include "BasicClientNetCtl.h"
#include "BasicServerNetCtl.h"
#include "ConsoleView.h"
#include "LedDriver.h"
using namespace std;

/*
 * Application dev launcher
 */

/*
 * Method to start the server
 */
int server(char* argv[]){
    /*
     * Creating a BasicServerNetCtl, extending ServerNetCtl.
     */
    ServerNetCtl* snc= new BasicServerNetCtl(argv[2],argv[3]);
    /*
     * Creating the driver we want to control our appliance
     */
    Driver * cd = new LedDriver();
    ServerCtl* sc = new ServerCtl(snc,cd);
    sc->run();
    return 0;
}

/*
 * Method to start a client with ConsoleView and BasicClientNetCtl
 */
int bvbnclient(char* argv[]){
    View* v = new ConsoleView();
    ClientNetCtl* cnc = new BasicClientNetCtl(argv[2],argv[3]);
    ClientCtl* sc = new ClientCtl(v,cnc);
    sc->run(argv[4]);
    return 0;
}

int main(int argc, char *argv[]){

    if(strcmp (argv[1],"server") == 0){
        server(argv);
    }else if(strcmp (argv[1],"client") == 0){
        bvbnclient(argv);
    }else {
        cout << "Usage client : " << argv[0] << " client host port start|stop|get" << endl;
        cout << "Usage server : " << argv[0] << " server host port"<< endl;
    }
    return 0;
}
