#include "BasicServerNetCtl.h"

BasicServerNetCtl::BasicServerNetCtl()
{

}

BasicServerNetCtl::BasicServerNetCtl(string host,string port) : ServerNetCtl(host,port)
{

}

BasicServerNetCtl::~BasicServerNetCtl()
{

}

//Listen to the server port, create a session when a connection is made
tcp::socket BasicServerNetCtl::listen()
{
    boost::asio::io_service io_service;

    tcp::acceptor a(io_service, tcp::endpoint(tcp::v4(), stoi(this->getPort())));
    for (;;)
    {
        socket_ptr sock(new tcp::socket(io_service));
        a.accept(*sock);
        boost::thread t(boost::bind(session, sock)); // A basic a new session to the incoming socket
    }

}

//Manage interaction with one connection
void BasicServerNetCtl::session(socket_ptr sock)
{
  try
  {
        using namespace std;
        char data[max_length];
        boost::system::error_code error;
        //Receive request (TODO: untested overflow)
        size_t length = sock->read_some(boost::asio::buffer(data), error);

        //Adding a null byte at the end of the entry
        if(length<max_length){
            data[length] = 0x0;
        }else{
            data[max_length] = 0x0;
        }
        cout << data << endl;

        //Handling request (changing CoffeePot state if needed)
        BasicServerNetCtl::handleRequest(data);

        //Replying
        char resp[max_length];
        string strResp = BasicServerNetCtl::generateResponse();
        strcpy(resp,strResp.c_str());
        size_t resplen = strlen(resp);
        resp[resplen] = 0x0;
        cout << "Response is : " << endl << resp << endl;
        boost::asio::write(*sock, boost::asio::buffer(resp,resplen));
  }
  catch (std::exception& e)
  {
    //Basic exception handling, loging on the standard output
    std::cerr << "Exception in thread: " << e.what() << "\n";
  }
}

//Produce a string representing the response
//It will always and only be replying "OK, here is the web page you asked"
string BasicServerNetCtl::generateResponse()
{
    PotState& potstate = PotState::getInstance();

    //Generating an html page
    string content ="";
    content += "<!DOCTYPE html>\n";
    content += "<html>\n";
        content += "<head>\n";
            content += "<link href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\" rel=\"stylesheet\">\n";
        content += "</head>\n";
        content += "<body>\n";
            content += "<div class=\"well container text-center\">\n";
                content += "<h1>CoffeePotController</h1>\n";
                content += "<p>Ce serveur est une cafetière</p>\n";

                // Printing the pot state
                content+="<p>";
                if(potstate.getState()){
                    content+= "La cafetière est actuellement en marche depuis : ";
                    content+= PotState::getInstance().getDate();
                }else{

                    content+= "La cafetière est actuellement éteinte.";
                }
                content+="</p>";
                    content += "<div class=\"row\">";
                        content += "<div class=\"col-xs-6 text-right\">\n";
                            content += "<form action=\"/\" method=\"get\">";
                                content += "<input type=\"hidden\" name=\"action\" value=\"on\">";
                                content += "<button type=\"submit\">Allumer</button>";
                                content += "</form>";
                        content += "</div>";
                        content += "<div class=\"col-xs-6 text-left\">\n";
                            content += "<form action=\"/\" method=\"get\">";
                                content += "<input type=\"hidden\" name=\"action\" value=\"off\">";
                                content += "<button type=\"submit\">Eteindre</button>";
                            content += "</form>";
                        content += "</div>";
                    content += "</div>";
                content += "</div>";
            content += "</div>";
        content += "</body>\n";
    content += "</html>\n";

    //Generating the response header
    string respStr = "HTTP/1.1 200 OK\r\n";
    respStr += "Content-Type: text/html; charset=utf-8\r\n";
    respStr += "Server: CoffeePotServer v1\r\n";
    respStr += "Content-Length: ";
    respStr += to_string(strlen(content.c_str()));
    respStr += "\r\n";
    respStr += "Connexion: closed\r\n\r\n";

    //Concat header to html page
    respStr+= content;

    return respStr;
}

//Handle the request
//Search for keyword ?action=XX in the first line of the request
void BasicServerNetCtl::handleRequest(char* req)
{
    string request = req;
    vector<string> results;

    boost::split(results,request,[](char c){return c == '\r';});
    if(results.at(0).find("?action=on") != string::npos){
        PotState::getInstance().setState(true);
        PotState::getInstance().setDate();
    }else if(results.at(0).find("?action=off") != string::npos){
        PotState::getInstance().setState(false);
    }
}
