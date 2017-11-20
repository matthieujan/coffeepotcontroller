#include <HtcpcpRequest.h>

using namespace std;

HtcpcpRequest::HtcpcpRequest() : super(){

}

HtcpcpRequest::HtcpcpRequest(string raw) : super(raw){

}

HtcpcpRequest::~HtcpcpRequest(){

}

bool HtcpcpRequest::isValid(){
    return super::isValid();
}
