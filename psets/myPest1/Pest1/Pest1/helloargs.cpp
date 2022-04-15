#include <iostream>
#include <string>
using namespace std;int main(unsigned int argc, char*argv[]) {
	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdout, NULL, _IONBF, 0);

	for (int i = 0; i < argc; i++) {
		if (i == 0) continue;
		cout << "Hello " << argv[i] << "!\n ";
	}
		
	

	// Use system("pause") to prevent the terminal from disappearing
	// as soon as the program terminates as in Visual Studio sometimes.
	// system("pause");
	return EXIT_SUCCESS;
}
