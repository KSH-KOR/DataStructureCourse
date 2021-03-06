/// Author Youngsup Kim, idebtor@gmail.com
/// 2020/11/20	Creation
#ifndef HASH_H
#define HASH_I

#include <list>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

struct Hash {                           // vector<list<int>> hashtable may be used
	int         tablesize;              // hash table size
	list<int>*  hashtable;              // pointer to an array of buckets 
	int         nelements;              // number of elements in table
	double      threshold;              // rehashing threshold

	Hash(int size = 2, double lf = 1.0) {  	// a magic number, use a small prime 
		tablesize = size;                 	// using list<int> for a pedagogical purpose
		hashtable = new list<int>[size];	// but vector<list<int>> may be used
		nelements = 0;
		threshold = lf;                    	// rehashes if loadfactor >= threshold
	}
	~Hash() {
		delete[] hashtable;
	}
};

// Notice that ht is passed by reference when its pointer may be changed inside 
// except erase() and show(). Passing by reference may help to run the code faster. 
int hashfunction(Hash* ht, int key);     // hash function for int key
void rehash(Hash*& ht);                  // rehashes - doubles its tablesize
bool insert(Hash*& ht, int key);         // inserts key & rehashes if loadfactor >= threshold
bool erase(Hash*& ht, int key);          // erases key, returns true if successful 
list<int> find(Hash* ht, int key);    	// finds key in table
void clear(Hash* &ht);                  // clear the table

void show(Hash*& ht, bool show_empty=false);  // show the table

int nextprime(int x);                       // returns the next prime 
int tablesize(Hash* ht);                    // returns hash table size
int nelements(Hash* ht);                    // returns number of elements in the table
double loadfactor(Hash* ht);                // returns nelements/tablesize
double threshold(Hash* ht);                 // returns threshold(or max_loadfactor)
void threshold(Hash*& ht, double th);       // sets threshold and rehashes if needed

#endif