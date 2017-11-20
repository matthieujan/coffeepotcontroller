#include <HtcpcpMessage.h>

using namespace std;

HtcpcpMessage::HtcpcpMessage(){
    m_raw = "";
    m_isValid = false;
}

HtcpcpMessage::HtcpcpMessage(string raw)
{
    m_isValid = false;
    m_raw = raw;
}

HtcpcpMessage::~HtcpcpMessage()
{

}

string HtcpcpMessage::getRaw()
{
    return m_raw;
}

bool HtcpcpMessage::isValid()
{
    return m_isValid;
}

void HtcpcpMessage::setValid(bool isValid){
    m_isValid = isValid;
}
