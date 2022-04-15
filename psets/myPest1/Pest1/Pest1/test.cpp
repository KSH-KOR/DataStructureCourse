
#include <iostream>

int main(unsigned int argc, char *argv[]) {
	for (size_t i = 0; i < argc; i++) { 
		std::cout << i + ": "; 
		std::cout << argv[i] << std::endl; 
	}
}