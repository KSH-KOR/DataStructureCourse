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

pair<char, int> get_op(string opstr) {
    char op;
    size_t x;
    do {
        stringstream ss;
        string str;
        cout << "Enter an operator( " << opstr << "): ";
        getline(cin, str);
        ss << str;
        ss >> op;
        x = opstr.find(op);
    } while (opstr.find(op) == string::npos);
    return pair<char, int>(op, x);
}

int no_match_op(int a, int b) {
    return 0;
}


int main() {
    int (*func[4])(int, int) = { add , sub, mul, dvd };
    string opster = { "+-*/" };

    int a = get_int();
    pair<char,int> op = get_op(opster);
    int b = get_int();

    cout << a << op.first << b << " = " << func[op.second](a, b) << endl;

    return 0;
}
