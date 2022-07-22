#include <iostream>
#include <cmath>

int main() {
  double a;
  double b;
  double c;
  
  double root1;
  double root2;
  
  std::cout << "Enter a: ";
  std::cin >> a;
  std::cout << "Enter b: ";
  std::cin >> b;
  std::cout << "Enter c: ";
  std::cin >> c;
  
  root1 = (-b + sqrt(b * b - 4 * a * c))/(2 * a);
  root2 = (-b - sqrt(b * b - 4 * a * c))/(2 * a);
  
  std::cout << "Value of root1: " << root1 << std::endl;
  std::cout << "Value of root2: " << root2 << std::endl;  
}