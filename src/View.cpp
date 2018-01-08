#include "View.h"

View::View()
{

}

View::~View()
{

}

// Generic ask function using the command line
string View::ask()
{
    string input;
    cout << "Entrer une commande" << endl;
    cin >> input;
    return input;
}

