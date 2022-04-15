#include <iostream>
#include <string>
using namespace std;

void hellofunc(int n, char *names[]);

int main(int argc, char*argv[]) {
    const int N =256;
    char *names[N];
    // Use setvbuf() to prevent the output from buffered on console.
    setvbuf(stdout, NULL, _IONBF, 0);
    
    int i=0;
    while(1){
        cout << "Enter your name : ";
        names[i] = new char;
        cin.getline(names[i], N);
        if(names[i] == "\n") break;
        i++;
    }

    
    for(int i=0;i<argc;i++) cout << argv[i] << endl;
    hellofunc(N, names);

    // Use system("pause") to prevent the terminal from disappearing
    // as soon as the program terminates as in Visual Studio sometimes.
    system("pause");
    return EXIT_SUCCESS;
}
