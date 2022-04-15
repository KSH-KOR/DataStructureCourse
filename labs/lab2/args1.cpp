// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
// Lab 2:
//	1. Using vector class in c++
//	2. ranged-for loop
//	3. function overloading
//	4. include file
//  5. not using `using namespace std;`

#include<iostream>
#include<vector>

void printfunc(int n, char *args[]);
void printfunc(std::vector<std::string> names);

int main(int argc, char *argv[]) {
	std::cout << "Hello World!" << std::endl;

	return 0;
}