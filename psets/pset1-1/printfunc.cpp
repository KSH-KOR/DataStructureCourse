#include <iostream>
void printfunc(int n, char *names[]) {
    for (int i = 0; i < n; i++) {
		if (i == 0) continue;
		std::cout << "Hello " << names[i] << std::endl;
	}
}
