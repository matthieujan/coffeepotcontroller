#include <HtcpcpMessage.h>

using namespace std;

HtcpcpMessage::HtcpcpMessage(){
    rawMessage = "Test";
}

HtcpcpMessage::HtcpcpMessage(string raw)
{
    this->rawMessage = raw;
}

HtcpcpMessage::~HtcpcpMessage()
{

}

string HtcpcpMessage::getCmd()
{
    return "test";
}

string HtcpcpMessage::getRaw()
{
    return rawMessage;
}
