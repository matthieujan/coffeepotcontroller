#ifndef DEF_HTCPCPMESSAGE_H
#define DEF_HTCPCPMESSAGE_H

#include <string>
#include <iostream>
#include <boost/algorithm/string.hpp>
using namespace std;

class HtcpcpMessage
{
    public:
        HtcpcpMessage();
        HtcpcpMessage(string raw);
        ~HtcpcpMessage();
        string getRaw();
        virtual bool isValid();

    private:
        string m_raw;
        bool m_isValid;

    protected:
        void setValid(bool isValid);
};
#endif
