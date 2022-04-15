/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
Signed: shinhookim Student Number: 21900136
*/


#include <iostream>
#include <sstream>
using namespace std;

int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }
int sub(int a, int b) { return a - b; }
int dvd(int a, int b) { if (b != 0) return a / b; else return 0; }

int get_int() {
    int x;
    do {
        cout << "Enter an integer";
        string str;
        getline(cin, str);
        try {
            x = stoi(str);
            break;
        }
        catch (invalid_argument e) {
            cerr << e.what() << " error occurred. Retry~" << endl;
        }
    } while (true);
    return x;
}

char get_op(string opstr) {
    char op;
    do {
        stringstream ss;
        string str;
        cout << "Enter an operator( " << opstr << "): ";
        getline(cin, str);
        ss << str;
        ss >> op;

    } while (opstr.find(op) == string::npos);
    return op;
}

int no_match_op(int a, int b) {
    return 0;
}


int main() {
    int a = get_int();
    char op = get_op("+-*/");
    int b = get_int();
    int result=0;

    cout << "A: " << a << "\noperator: " << op << "\nB: " << b << endl;

    int (*func)(int, int) = no_match_op;
    switch (op) {
        case '+':
            func = add;
            break;
        case '-':
            func = sub;
            break;
        case '*':
            func = mul;
            break;
        case '/':
            func = dvd;
            break;
        defalut: break;
    }
    cout << a << op << b << " = " << func(a, b) << endl;

    return 0;
}
