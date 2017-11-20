#include <iostream>
#include <string.h>

using namespace std;

int htcpcp(){
    return 0;
}

int main(int argc, char *argv[]){

    for(int i = 0;i<argc;i++)
    {
        if(strcmp (argv[i],"htcpcp") == 0){
            htcpcp();
        }
    }
    return 0;
}
