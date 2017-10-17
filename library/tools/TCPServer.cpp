
#include "TCPServer.h"


TCPServer::TCPServer()
{
  std::cout << "Start TCP-Server"<< std::endl;
  fSocketID = 0;
  
}


TCPServer::~TCPServer()
{
  std::cout << "Close TCP-Server" << std::endl;
  if(fSocketID >0)
    close(fSocketID);

}


void TCPServer::OpenSocket()
{
  std::cout << "Open Socket " << std::endl;
  //fSocketID = socket(AF_INET,SOCK_STREAM,0);
  fSocketID = socket(AF_INET,SOCK_DGRAM,0);

  

}
