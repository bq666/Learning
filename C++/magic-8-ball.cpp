#include <iostream>
#include <cstdlib>

int main(){
  std::cout << "MAGIC 8-BALL: ";
  srand(time(NULL));
  int answer = std::rand() % 6;
  // std::cout << answer;
  switch (answer){
    case 1 :
      std::cout << "It is certain.";
      break;
    case 2 :
      std::cout << "It is decidedly so.";
      break;
    case 3 :
      std::cout << "Yes - definitely.";
      break;
    case 4 :
      std::cout << "You may rely on it.";
      break;
    case 5 :
      std::cout << "As I see it, yes.";
      break;
    case 6 :
      std::cout << "Most likely.";
      break;
    case 0 :
      std::cout << "Outlook good.";
      break;
  }
}