#include <iostream>
#include <stdlib.h>

int main() {
  srand (time(NULL));
  int computer = rand() % 3 + 1;
  int user = 0;
	
  std::cout << "====================\n";
  std::cout << "rock paper scissors!\n";
  std::cout << "====================\n";

  std::cout << "1) ✊\n";
  std::cout << "2) ✋\n";
  std::cout << "3) ✌️\n";

  std::cout << "shoot! ";
  std::cin >> user;
  
  std::cout << "Computer choice: " << computer << std::endl;
  std::cout << "User choice: " << user << std::endl;

  
  if(computer == user){
    std::cout << "Remis\n";
    return 0;
  };
  
  switch (computer){
    case 1:
      if(user == 2){
        std::cout << "User win\n";
      } else {
        std::cout << "Computer win\n";
      }
      break;
    case 2:
      if(user == 3){
        std::cout << "User win\n";
      } else {
        std::cout << "Computer win\n";
      }
      break;
    case 3:
      if(user == 1){
        std::cout << "User win\n";
      } else {
        std::cout << "Computer win\n";
      }
      break;
  }
  
  
}