
#include "zlasdtest/test.hpp"

#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  int choice = 0;
  std::cout << "Lasd Libraries 2024" << std::endl;

  do{
    std::cout << "1: To Run LASDTEST" << std::endl;
    std::cout << "2: To Run MYTEST" << std::endl;
    std::cout << "Any Other Key: To Close" << std::endl;
    std::cin >> choice;
    if(choice == 1){
      lasdtest();
    }
    else if(choice == 2){
      mytest();
    } 
  } while (choice == 1 || choice == 2);
  

  return 0;
}
