#ifndef DEF_HTCPCPREQUEST_H
#define DEF_HTCPCPREQUESTH

#include <string>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <HtcpcpMessage.h>

using namespace std;

class HtcpcpRequest : public HtcpcpMessage
{
    public:
        HtcpcpRequest();
        HtcpcpRequest(string raw);
        ~HtcpcpRequest();
        bool isValid();

    protected:
        typedef HtcpcpMessage super;
};
#endif
