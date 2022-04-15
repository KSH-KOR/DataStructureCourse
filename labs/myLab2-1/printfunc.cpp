#include <iostream>
#include <vector>

void printfunc(int n, char *names[]) {
	for (int i = 0; i < n; i++){
		std::cout << "Hello: " << names[i] << "!" << std::endl;
    }
}

void printfunc(std::vector<std::string> names){
  //names.erase(names.begin());
	for(std::string s: names){
    std::cout << "Range based for loops: " << s << "!" << std::endl;
  }
}

