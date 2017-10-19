#include <iostream>
#include <stdlib.h>


#include "../tools/TCPtransmitter.h"


int main()
{
  std::cout << "Starte Programm:" << std::endl;


  
  TCPtransmitter* cSender = new TCPtransmitter(9000);
  std::string Ip = "192.168.1.4";
  cSender->SetIp(Ip);
  cSender->Connect();
  std::string cMessage;
  int size;
  
  //senden Funktioniert:  
  do
    {
      std::cin >> cMessage;
      cSender->Send(cMessage);
    }
  while(cMessage != "quit()");
  
  delete cSender;


}
