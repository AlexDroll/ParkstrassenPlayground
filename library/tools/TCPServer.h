
#ifndef TCPSERVER_H
#define TCPSERVER_H


#include <iostream>
#include <stdlib.h>

#include <sys/socket.h>
#include <unistd.h>

class TCPServer
{
 public:
  TCPServer();
  ~TCPServer();


  void OpenSocket();

 private:
  int fSocketID;





};






#endif
