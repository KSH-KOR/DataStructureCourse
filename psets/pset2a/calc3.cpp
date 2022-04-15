/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
Signed: shinhookim Student Number: 21900136
*/


#include <iostream>
#include <sstream>
#include <map>
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

char get_op(map<char, int(*)(int, int)> fpMap) {
    char op;
    string opster;
    for (auto x : fpMap) opster += x.first;
    do {
        stringstream ss;
        string str;
        cout << "Enter an operator( " << opster << "): ";
        getline(cin, str);
        ss << str;
        ss >> op;
        if (fpMap.find(op) != fpMap.end()) break;
    } while (true);
    return op;
}

int no_match_op(int a, int b) {
    return 0;
}


int main() {
    map<char, int (*)(int, int)> fpMap = {
        make_pair('+', add),
        make_pair('-', sub),
        make_pair('*', mul),
        make_pair('/', dvd)
    };

    int a = get_int();
    char op = get_op(fpMap);
    int b = get_int();

    cout << a << op << b << " = " << fpMap[op](a, b) << endl;

    return 0;
}
