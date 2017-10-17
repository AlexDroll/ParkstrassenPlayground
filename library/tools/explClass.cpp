#include "explClass.h"


expClass::expClass()
{
  std::cout << "Kontruktor" << std::endl;
}

expClass::~expClass()
{
  std::cout << "Destruktor" << std::endl;

}



void expClass::print(std::string cString)
{
  std::cout << cString << std::endl;


}
