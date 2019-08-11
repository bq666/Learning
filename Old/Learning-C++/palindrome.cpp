#include <iostream>

// Define is_palindrome() here:
bool is_palindrome(std::string text){  
	for(int i = 0, j = text.length() - 1; i < j; i++, j--){
      if(text[i] != text[j]){
        return false;
      }
    }     
  return true;
}

int main() {
  std::cout << is_palindrome("madam") << "\n";
  std::cout << is_palindrome("ada") << "\n";
  std::cout << is_palindrome("lovelace") << "\n";
  
}