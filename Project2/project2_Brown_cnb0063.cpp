# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include <ctime>

using namespace std;
//prototypes
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
/* Input: A_alive indicates whether Aaron is alive */
/* B_alive indicates whether Bob is alive */
/* C_alive indicates whether Charlie is alive */
/* Return: true if at least two are alive */
/* otherwise return false */
/*
* Add other function prototypes below
*/
void test_at_least_two_alive(void);
/* This is a test driver for at_least_two_alive() */
/*
* Add more prototypes for other test drivers below
*/
int main() {
/*
* This is the main function
* ...
*/
}
/* Implementation of at_least_two_alive() */
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
/* add the implementation below */
}
/* Implementation of the test driver for at_least_two_alive() */
void test_at_least_two_alive(void) {
    cout << “Unit Testing 1: Function – at_least_two_alive()\n”;
    cout << “Case 1: Aaron alive, Bob alive, Charlie alive\n”;
    assert(true == at_least_two_alive(true, true, true));
    cout << “Case passed ...\n”;
    cout << “Case 2: Aaron dead, Bob alive, Charlie alive\n”;
    assert(true == at_least_two_alive(false, true, true));
    cout << “Case passed ...\n”;
/* add test cases 4-6 below */
}