#ifndef TCPTRANSMITTER_H
#define TCPTRANSMITTER_H


#include <iostream>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <string.h>
#include <stdio.h>




class TCPtransmitter
{
 public:
  TCPtransmitter(int cPort);
  ~TCPtransmitter();

  void SetIp(std::string cAddress);

  void Connect();

  void Send(std::string cMessage);

  std::string Listen();

  int GetDescriptor();

  void Test();
  
  
 private:
  struct sockaddr_in fAddress;
  
  int fPort;

  int fDescriptor;

  char* fBuffer;

  int fBufferSize;
  
  std::string fIp;

  





};





#endif
