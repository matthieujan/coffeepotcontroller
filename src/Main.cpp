#include <iostream>
#include <string>
#include "HtcpcpMessage.h"

using namespace std;

int main(){
    HtcpcpMessage message("Brew test");
    cout << "Test :"<< message.getRaw() << endl;
    return 0;
}
