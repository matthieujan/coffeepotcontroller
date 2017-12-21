#ifndef DEF_POTSTATE_H
#define DEF_POTSTATE_H

#include <string>
#include <iostream>

using namespace std;

class PotState
{
    public:
        PotState();
        ~PotState();
        bool isOn();
        void setOn(bool value);
        string getImage();
        void setImage(string value);

    private:
        string image;
        bool on;
};
#endif
