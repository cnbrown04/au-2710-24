// Name: Caleb Brown
// Auburn ID: cnb0063
// Filename: project2_Brown_cnb0063.cpp
// To compile on JetBrains: Use the compile button in the top right of the window.

// Sources: cplusplus.com (https://cplusplus.com/reference/) (https://cplusplus.com/reference/iomanip/)

# include <iostream>
# include <cstdlib>
# include <cassert>
# include <ctime>

using namespace std;

// Initializing functions.
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void test_at_least_two_alive();

void Aaron_shoots1(bool& B_alive, bool& C_alive);
void testAaron1();

void Bob_shoots(bool& A_alive, bool& C_alive);
void testBob();

void Charlie_shoots(bool& A_alive, bool& B_alive);
void testCharlie();

void Aaron_shoots2(bool& B_alive, bool& C_alive);
void testAaron2();

void addWinner(bool A, bool B, bool C);
void pause();

const int finalI = 10000; // How many times should the program run?
const int aProb = 33; // Probability of Aaron hitting a shot. (percentage)
const int bProb = 50; // Probability of Bob hitting a shot. (percentage)
const int cProb = 100; // Probability of Charlie hitting a shot. (percentage)

int i; // Iterator
int firstShot; // If Aaron has shot his shot.
int aWins; // Amt of wins for Aaron.
int bWins; // Amount of wins for Bob.
int cWins; // Amount of wins for Charlie.
int aWins1; // Aaron wins for first round before they get reset for second round.

int main() {
    srand(time(nullptr)); // Random time.

    test_at_least_two_alive();
    pause(); // Pause() is the Press any key to continue function.

    testAaron1();
    pause();

    testBob();
    pause();

    testCharlie();
    pause();

    testAaron2();
    pause();

    cout << "Ready to test strategy 1 (run 10000 times):\n";
    pause();

    for (i = 0; i < finalI; i++) { // Loops through 10000 times or whatever FinalI is.
        bool A = true, B = true, C = true; // Resets everyone to be alive.
        while (at_least_two_alive(A, B, C)) { // If there are two people alive, do the loop.
            if (A) { // If Aaron is alive, shoot.
                Aaron_shoots1(B, C);
            }
            if (B) { // If Bob is alive, shoot.
                Bob_shoots(A, C);
            }
            if (C) { // If Charlie is alive, shoot.
                Charlie_shoots(A, B);
            }
        }
        addWinner(A, B, C); // Only runs after only one person is alive. Adds a win to whomever is alive.
    }

    // Self explanatory.
    cout << "Aaron won " << aWins << "/" << finalI << " duels or " << ((float)aWins / (float)finalI) * 100 << "%\n"; // Percentage calculation with floats.
    cout << "Bob won " << bWins << "/" << finalI << " duels or " << ((float)bWins / (float)finalI) * 100 << "%\n";
    cout << "Charlie won " << cWins << "/" << finalI << " duels or " << ((float)cWins / (float)finalI) * 100 << "%\n";

    cout << "\nReady to test strategy 2 (run 10000 times):\n";
    pause();

    aWins1 = aWins; // Store the wins from the first round.
    aWins = 0; // Reset all the win numbers.
    bWins = 0;
    cWins = 0;

    for (i = 0; i < finalI; i++) { // Read comments above, same.
        bool A = true, B = true, C = true;
        firstShot = true; // Sets the firstShot Aaron takes to true, so he doesnt take it.
        while (at_least_two_alive(A, B, C)) {
            if (A) {
                Aaron_shoots2(B, C); // Aaron misses his first shot intentionally.
            }
            if (B) {
                Bob_shoots(A, C);
            }
            if (C) {
                Charlie_shoots(A, B);
            }
        }
        addWinner(A, B, C);
    }

    cout << "Aaron won " << aWins << "/" << finalI << " duels or " << ((float)aWins / (float)finalI) * 100 << "%\n";
    cout << "Bob won " << bWins << "/" << finalI << " duels or " << ((float)bWins / (float)finalI) * 100 << "%\n";
    cout << "Charlie won " << cWins << "/" << finalI << " duels or " << ((float)cWins / (float)finalI) * 100 << "%\n";

    // If Aaron has more wins, that strategy wins.
    if (aWins > aWins1) {
        cout << "\nStrategy 2 is better than Strategy 1";
    } else {
        cout << "\nStrategy 1 is better than Strategy 2";
    }

}

/* Implementation of at_least_two_alive() */
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
    if (A_alive) { // Readable.
        if (B_alive) {
            return true;
        } else if (C_alive) {
            return true;
        } else {
            return false;
        }
    } else if (B_alive) {
        if (C_alive) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
    int random = rand()%100; // Random number calculation.
    if (C_alive) {
        if (random < aProb) { // Checks if the random number is greater than the probability.
            C_alive = false;
        }
    } else {
        if (random < aProb) {
            B_alive = false;
        }
    }
}

void Bob_shoots(bool& A_alive, bool& C_alive) {
    int random = rand()%100;
    if (C_alive) {
        if (random < bProb) {
            C_alive = false;
        }
    } else {
        if (random < bProb) {
            A_alive = false;
        }
    }
}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
    int random = rand()%100;
    if (B_alive) {
        if (random < cProb) {
            B_alive = false;
        }
    } else {
        if (random < cProb) {
            A_alive = false;
        }
    }
}

// Only change made with this function from the other functions is
// Aaron intentionally misses (doesn't take) his first shot.
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
    int random = rand()%100;
    if (firstShot == false) {
        if (C_alive) {
            if (random < aProb) {
                C_alive = false;
            }
        } else {
            if (random < aProb) {
                B_alive = false;
            }
        }
    } else {
        firstShot = false;
    }
}

// Adds count to whomever was still alive.
void addWinner(bool A, bool B, bool C) {
    if (A) {
        aWins++;
    } else if (B) {
        bWins++;
    } else if (C) {
        cWins++;
    }
}

/* Implementation of the test driver for at_least_two_alive() */
void test_at_least_two_alive(void) {
    cout << "Unit Testing 1: Function – at_least_two_alive()\n";
    cout << "Case 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(true, true, true));
    cout << "Case passed ...\n";
    cout << "Case 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(false, true, true));
    cout << "Case passed ...\n";
    cout << "Case 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(true == at_least_two_alive(true, false, true));
    cout << "Case passed ...\n";
    cout << "Case 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(true == at_least_two_alive(true, true, false));
    cout << "Case passed ...\n";
    cout << "Case 5: Aaron dead, Bob dead, Charlie alive\n";
    assert(false == at_least_two_alive(false, false, true));
    cout << "Case passed ...\n";
    cout << "Case 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(false == at_least_two_alive(false, true, false));
    cout << "Case passed ...\n";
    cout << "Case 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(true, false, false));
    cout << "Case passed ...\n";
    cout << "Case 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(false, false, false));
    cout << "Case passed ...\n";
}

// To be completely honest, there was no way I could test
// these next functions without altering the shoot functions
// and that wasn't in the assignment that I could.
void testAaron1() {
    cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
    cout << "Case 1: Bob alive, Charlie alive\n";
    cout << "Aaron is shooting at Charlie\n";
    cout << "Case 2: Bob dead, Charlie alive\n";
    cout << "Aaron is shooting at Charlie\n";
    cout << "Case 3: Bob alive, Charlie dead\n";
    cout << "Aaron is shooting at Bob.\n";
}

void testBob() {
    cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
    cout << "Case 1: Aaron alive, Charlie alive\n";
    cout << "Bob is shooting at Charlie\n";
    cout << "Case 2: Aaron dead, Charlie alive\n";
    cout << "Bob is shooting at Charlie\n";
    cout << "Case 3: Aaron alive, Charlie dead\n";
    cout << "Bob is shooting at Bob.\n";
}

void testCharlie() {
    cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
    cout << "Case 1: Aaron alive, Bob alive\n";
    cout << "Charlie is shooting at Bob\n";
    cout << "Case 2: Aaron dead, Bob alive\n";
    cout << "Charlie is shooting at Bob\n";
    cout << "Case 3: Aaron alive, Bob dead\n";
    cout << "Charlie is shooting at Aaron.\n";
}

void testAaron2() {
    cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
    cout << "Case 1: Bob alive, Charlie alive\n";
    cout << "Aaron intentionally misses his first shot\n";
    cout << "Both Bob and Charlie are alive.\n";
    cout << "Case 2: Bob dead, Charlie alive\n";
    cout << "Aaron is shooting at Charlie\n";
    cout << "Case 3: Bob alive, Charlie dead\n";
    cout << "Aaron is shooting at Bob.\n";
}

// Pauses the program and waits for further input.
void pause() {
    cout << "Press any key to continue...";
    cin.ignore().get(); //Pause Command for Linux Terminal
}