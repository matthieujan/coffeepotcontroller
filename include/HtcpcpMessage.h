#ifndef DEF_HTCPCPMESSAGE_H
#define DEF_HTCPCPMESSAGE_H

#include <string>
#include <iostream>

using namespace std;

class HtcpcpMessage
{
    public:
        HtcpcpMessage();
        HtcpcpMessage(string raw);
        ~HtcpcpMessage();
        string getCmd();
        string getRaw();

    private:
        string rawMessage;
};
#endif
