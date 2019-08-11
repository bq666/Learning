#include <iostream>
#include <vector>
#include <string>

int main(){
  std::string input = "A whale of a deal!";
  std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  std::vector<char> result;
  for(int i = 0; i < input.size(); i++){
    for(int j = 0; j < vowels.size(); j++){
    	if(input[i] == vowels[j]){
        // std::cout << input[i] << std::endl;
        result.push_back(input[i]);
      };
    };  
      if(input[i] == 'u' || input[i] == 'e'){
      	result.push_back(input[i]);
    	}
  };
  for(int i = 0; i < result.size(); i++){
  	std::cout << result[i];  
  }  
}