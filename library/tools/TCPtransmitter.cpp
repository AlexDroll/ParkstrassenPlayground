#include "TCPtransmitter.h"


TCPtransmitter::TCPtransmitter(int cPort)
{
  fPort = cPort;

  std::cout << "Send to Port : " << fPort << std::endl;
  fDescriptor = -1;
  fDescriptor = socket(AF_INET, SOCK_STREAM,0);
  if(fDescriptor > 0)
    std::cout << "Socket angelegt mit Descriptor: " << fDescriptor << std::endl;

  fBufferSize = 1024;
  fBuffer = new char[1024];

  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_port = 9000;

  
}

TCPtransmitter::~TCPtransmitter()
{
  //CLose socket:
  close(fDescriptor);
  std::cout << "Socket closed" << std::endl;
}



void TCPtransmitter::SetIp(std::string cAddress)
{
  //struct sockaddr_in address;
  fIp = cAddress;
  fAddress.sin_family = AF_INET;
  fAddress.sin_port = htons (fPort);
  inet_aton (cAddress.c_str(), &fAddress.sin_addr);
  //fAddress = address;
  
}



void TCPtransmitter::Connect()
{
  if(connect(fDescriptor,(struct sockaddr *) &fAddress, sizeof (fAddress) ) == 0)
    std::cout << "Connected to "<< fIp << ":"<< fPort << std::endl;
  

}



void TCPtransmitter::Send(std::string cMessage)
{

  send(fDescriptor, cMessage.c_str(), strlen (cMessage.c_str()), 0);
  

}


std::string TCPtransmitter::Listen()
{
  
  int size = recv(fDescriptor, fBuffer, fBufferSize-1, 0);
  if( size > 0)
    fBuffer[size] = '\0';
  std::cout << fBuffer;
  std::string cMessage(fBuffer,size);
  return cMessage;
}


void TCPtransmitter::Test()
{
  do {
    int size = recv(fDescriptor, fBuffer, fBufferSize, 0);
      if( size > 0)
         fBuffer[size] = '\0';
      printf ("Nachricht erhalten: %s\n", fBuffer);
      if (strcmp (fBuffer, "quit()")) {
         printf ("Nachricht zum Versenden: ");
         fgets (fBuffer, fBufferSize, stdin);
         send(fDescriptor, fBuffer, strlen (fBuffer), 0);
       }
  } while (strcmp (fBuffer, "quit()") != 0);


}

int TCPtransmitter::GetDescriptor()
{
  return fDescriptor;
}
