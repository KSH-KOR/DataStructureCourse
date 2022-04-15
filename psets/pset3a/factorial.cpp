/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
Signed: shinhookim 분반: 03  Student Number: 21900136
*/
#include <iostream>

long long unsigned factorial(int n) {
	if(n==0 || n==1) return n;
    auto result = factorial(n-1) * n;
	return result;
}

int main() {
    std::cout << factorial(10) << std::endl;
    return 0;
}