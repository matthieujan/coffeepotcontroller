#include <HtcpcpResponse.h>

using namespace std;

HtcpcpResponse::HtcpcpResponse() : super(){

}

HtcpcpResponse::HtcpcpResponse(string raw) : super(raw){

}

HtcpcpResponse::~HtcpcpResponse(){

}

bool HtcpcpResponse::isValid(){
    return super::isValid();
}
