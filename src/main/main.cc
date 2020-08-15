#include <iostream>
#include "src/lib/solution.h"

using namespace std;

// Driver program to test above functions 
int main() 
{ 
    // build a BST with default size 11.
    BST b;
    b.push(3); 
    b.push(2); 
    b.push(15); 
    b.push(5); 
    b.push(4); 
    b.push(45); 
    b.print();
    cout << b.find(3) << endl;
    b.erase(3);
    b.print();
    cout << b.find(3) << endl;


        //                     3
        //         2                   15
        //                         5       45
        //                     4
                                            
        // print out 3 2 15 5 45 4, correct

    return 0; 
} 