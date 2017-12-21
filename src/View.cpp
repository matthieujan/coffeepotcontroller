#include "View.h"

View::View()
{

}

View::~View()
{

}

string View::ask()
{
    string input;
    cout << "Entrer une commande" << endl;
    cin >> input;
    return input;
}

