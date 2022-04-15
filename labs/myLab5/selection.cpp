/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
Signed: shinhookim Student Number: 21900136
*/

// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
// 
// selection sort 
// The selection sort improves on the bubble sort by making only one exchange 
// for every pass through the list. In order to do this, a selection sort 
// looks for the largest value as it makes a pass and, after completing the 
// pass, places it in the proper location. As with a bubble sort, after the 
// first pass, the largest item is in the correct place. After the second pass, 
// the next largest is in place. This process continues and requires n−1 passes 
// to sort n items, since the final item must be in place after the (n−1)st pass.
// Its time complexity is O(n^2).
//
// 2019/02/02: Created by idebtor@gmail.com
// 2021/01/20: comparator default argument added 
// 
// To build and run,
// Set #if 1 to activate main() function at the bottom of the file first. 
// > g++ -std=c++11 selection.cpp -o selection
// > ./selection
//
// To use DEBUG or test it, compile with -D option and turn #if 1 on.
// Then build it with -D option run it as shown below:
// > g++ -std=c++11 -DDEBUG selection.cpp -o selection
// > ./selection
//
// To add this function to a static library libsort.a, 
// 1. set #if 0 to deactivate main() function at the bottom of the file first. 
// 2. compile first to produce ~.o file. 
// 3. add it to libsort.a as shown below.
// > g++ -std=c++11 -c selection.cpp      # produce selection.o
// > ar r libsort.a selection.o           # insert or update selection.o in libsort.a
// > ar t libsort.a                       # show objects in libsort.a 
//
/******************************************************************************
  Lab05 - Understanding a better coding in C/C++
  - NMN(No magic number)
  - DRY(Don't repeat yourself)
  - Use new and delete instead of malloc(), free()
  - Use assert() after new to check the memory allocation status
  - rand() and mod operator %
  - Learn about a better coding after all.
*******************************************************************************/
#include <iostream>
#include <list>
#include <string>
#include <cassert>
using namespace std;

//## Step 1: NMN and DRY - Better coding in C++
//1.Replace `sort()` with an appropriate name. 
//2. Replace <stdio.h> which comes from C with <iostream> and `using namespace std;`. For example, replace `printf` with `cout`. 
//3. NMN: Find a magic number and replace it with a better code.
//4. DRY: Replace some repeated code with `printlist()` function in `printlist.cpp` provided. Add the following function prototype before you use it in selection.cpp. 

//## Step 2: Getting input n from the user and dynamic memory allocation

/*## ## Step 3: Adding a default comparator function pointer
As you experienced in `bubblesort.cpp`, add an third parameter to `selectionsort()` such that it can sort in both ascending and descending order.
1. Add a third parameter `comp` function pointer such that it may take either `more` or `less`.  Use `comp` functin pointer to compare two elements in the list.
2. Define two comparator functions, `more() and less()`. Place it just above `main()`.
3. Define the function prototype with a default comparator for ascending order. Place it just above `main()`.
*/

void printlist(int* list, int n, int show_n = 20, int per_line = 10);

bool more(int x, int y) { return x > y; }   // for descending order
bool less(int x, int y) { return x < y; }   // for ascending order 

void selectionSort(int* list, int n, bool (*comp)(int, int) = ::less) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (comp(list[j], list[min])) min = j;
        int temp = list[i];
        list[i] = list[min];
        list[min] = temp;
    }
}


#if 1
int main(int argc, char* argv[]) {
    //1. Comment out the following two lines you coded and add a new line with `int n = 0;`.
    /*
    int list[] = { 3, 4, 1, 7, 0, 9, 6, 5, 2, 8 };
    int n = sizeof(list)/sizeof(*list);
      */
      /*2. Get an array size n from the user and set it for `n`.
        - The `n` should be greater than 1.
        - If `n > 1`, break the while-loop since we got the proper `n`.
        - Let the user retry if `n` is invalid. (negative, not a number...)
        - Quit the program if the user enters `q`.
        - If necessary, include <string> header file to use functions such as `getline()` and `stoi()`.
        - Check your run with the sample solution `selectionx.exe`.
      */

    int n = 0;
    while (n <= 1) {
        cout << "Enter a number of samples to sort(q to quit): ";
        string str;
        size_t sz;
        int temp;
        getline(cin, str);
        if (str == "q") return 0;
        try {
            temp = stoi(str, &sz);
        }
        catch (...) {
            cout << "Retry -" << endl;
            continue;
        }
        if (str.substr(sz) != "" || temp < 0) {
            cout << "Retry -" << endl;
        }
        else {
            n = temp;
        }
    }

    /*
    3. Dynamic memory allocation in C++
      - Once you get a proper `n` from the user, use it to allocate an `int` array `list`.
      - Instead of using `malloc()` and `free()`, use `new` and `delete` in C++.
      - Use a pointer `int *list` and `new (nothrow) int[n]`.
      - Right after the allocation, use `assert()` to check that the allocation was successful as shown below:

  4. Generate random numbers from `0` to `n` and store them in `list`.
      */
    int* list = new(nothrow)int[n];
    assert(list != nullptr); //If `new` fails, it returns `nullptr`. If `list == nullptr`, then the process stops here. This is the simplest way of checking assertion in coding. 
    for (int i = 0; i < n; i++) list[i] = rand() % n; //- Use `rand() % n` which generates an integer between `0` and `n`. 

    // use printlist() to show the list initialized
    cout << "UNSORTED(" << n << "): " << endl;
    printlist(list, n);

    // ascending order 
    selectionSort(list, n);
    cout << "SORTED(" << n << "): " << endl;
    printlist(list, n);

    // descending order using more() fp.
    selectionSort(list, n, more);
    cout << "SORTED(" << n << "): descending using fp\n";
    printlist(list, n);

    delete[]list; //Use `delete` or `delete []` to free memory resources after use.
    cout << "Happy Coding~~" << endl;
    return 0;
}
#endif 
