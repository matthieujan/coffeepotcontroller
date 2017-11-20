#include <iostream>
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




int main(){

    int a = htcpcp();
    if(a != 0){
        cout << "Error : htcpcp"<< endl;
    }else{
        cout << "All good, for now"<< endl;
    }


    return 0;
}
