#ifndef DEF_VIEW_H
#define DEF_VIEW_H

#include <string.h>
#include <iostream>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>

using namespace std;

class View
{
    public:
        View();
        ~View();
        string ask();
};

#endif
