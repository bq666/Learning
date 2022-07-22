#include <iostream>

int main() {
  double pesos;
  double reais;
  double soles;
  
  double dollars;
  
  std::cout << "Enter number of Colombian Pesos: ";
  std::cin >> pesos;
  
  std::cout << "Enter number of Brazilian Reais: ";
  std::cin >> reais;
  
  std::cout << "Enter number of Peruvian Soles: ";
  std::cin >> soles;
  
  dollars = (0.052 * pesos) + (0.26 * reais) * (0.3 * soles);
  
  std::cout << "US Dollars = " << dollars << "$" << std::endl; 
}