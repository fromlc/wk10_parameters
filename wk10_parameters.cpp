//------------------------------------------------------------------------------
// wk10_parameters.cpp
// 
// examples of value and reference parameters
//------------------------------------------------------------------------------
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
// local functions
//------------------------------------------------------------------------------
int add_ints(int, int);
void no_swap(int, int);
void swap(int&, int&);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    int sum { };

    // call with literal arguments
    sum = add_ints(3, 5);

    int a = 7, b = 9;

    // call with variable arguments
    sum = add_ints(a, b);

    // call by value
    no_swap(1, 3);      // can't swap, literal values are rvalues
    no_swap(a, b);      // can't swap, arg values are copied and passed

    // call by reference
    //swap(1, 3);       // can't swap, literal args are rvalues
    no_swap(a, b);      // swap works, variable args are rvalues

    cout << "Hello World!\n";
}

//------------------------------------------------------------------------------
// -call with literal int arguments or variable int arguments
// -value of arguments is copied and assigned to parameter variables x and y
//------------------------------------------------------------------------------
int add_ints(int x, int y) {

    return x + y;
}

//------------------------------------------------------------------------------
// -call with literal int arguments or variable int arguments
// -tries to swap values of passed arguments
// -fails because arguments are evaluated, value is copied and
//   assigned to parameter variables x and y
//------------------------------------------------------------------------------
void no_swap(int x, int y) {

    int temp = x;
    x = y;
    y = temp;
}

//------------------------------------------------------------------------------
// -call with variable int arguments only
// -swaps values of passed arguments
// -succeeds because argument addresses are passed!
//------------------------------------------------------------------------------
void swap(int& x, int& y) {

    int temp = x;
    x = y;
    y = temp;
}
