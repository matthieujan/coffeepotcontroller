#include <CamDriver.h>

CamDriver::CamDriver() : super()
{

}

CamDriver::~CamDriver()
{

}

void* CamDriver::get()
{
    string* data = new string("data");
    return data;
}

void CamDriver::set()
{
    cout << "CamDriver set" <<endl;
}
