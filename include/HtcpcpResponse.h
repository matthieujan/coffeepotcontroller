#ifndef DEF_HTCPCPRESPONSE_H
#define DEF_HTCPCPRESPONSE_H

#include <string>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <HtcpcpMessage.h>

using namespace std;

class HtcpcpResponse : public HtcpcpMessage
{
    public:
        HtcpcpResponse();
        HtcpcpResponse(string raw);
        ~HtcpcpResponse();
        bool isValid();

    protected:
        typedef HtcpcpMessage super;
};
#endif
