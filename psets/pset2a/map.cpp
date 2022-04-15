/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
Signed: shinhookim Student Number: 21900136

*/

#include <iostream>
#include <map>
using namespace std;
int main() {
	cout << "declare a map variable called table\n";
	map<string, int> table;

	cout << "initialize table using array[], insert(), pair<>, make_pair()\n";
	cout << "your code here\n";
	string name[] = { "Adam", "John", "Paul", "Pete" };
	int age[] = {11, 21, 15, 10};
	size_t N = sizeof(name) / sizeof(name[0]);
	for (int i = 0; i < N; i++) {
		if(i%2==0) table.insert(make_pair(name[i], age[i]));
		if(i%2!=0) table.insert(pair<string, int>(name[i], age[i]));
	}

	cout << "print table using range-based for loop\n";
	cout << "your code here\n";
	for (pair<string, int> x : table) {
		cout << "name: " << x.first << "\tage: " << x.second << endl;
	}

	cout << "print table using iterator\n";
	cout << "your code here\n";
	for (map<string, int>::iterator it = table.begin(); it != table.end(); it++) {
		cout << "name: " << (*it).first << "\tage: " << (*it).second << endl;
	}

	cout << "define and initialize chart using pair<> and make_pair() only\n";
	cout << "your code here\n";
	map<char, int> chart{
		pair<char, int>('A', (int)'A'),
		pair<char, int>('B', (int)'B'),
		make_pair('C', (int)'C'),
		make_pair('D', (int)'D')
	};

	cout << "print chart using range-based for loop\n";
	cout << "your code here\n";
	for (pair<char, int> x : chart) {
		cout << "ascii: " << x.first << "\tcode: " << x.second << endl;
	}
	cout << chart['B'] << endl; 
	return 0;
}