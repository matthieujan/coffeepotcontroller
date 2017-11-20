#include <iostream>
#include <vector>
#include <string>
#include "HtcpcpMessage.h"

using namespace std;

int htcpcp(){
    string raw = "I'm totaly not on crack i swear\n";
    raw+="Beside, even if i was, do you really care ?";
    HtcpcpMessage* mess = new HtcpcpMessage(raw);
    if(!mess->isValid()){
        cout << mess->getRaw() << endl;
        cout << "The server you're contacting is on crack" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]){


    for(int i = 0;i<argc;i++)
    {
        if(strcmp (argv[i],"htcpcp") == 0){
            htcpcp();
        }
    }
    return 0;
}
