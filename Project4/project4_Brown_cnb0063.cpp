/* Name: Caleb Brown
 Auburn ID: cnb0063
 Filename: project4_Brown_cnb0063.cpp
 To compile on JetBrains: Use the compile button in the top right of the window.
 To compile using Auburn Server: Login to the auburn server after uploading the file
    and then use the command g++ project3_Brown_cnb0063.cpp -o project3 and then
    use the command ./project3 to execute the compiled program.

 Sources: cplusplus.com (https://cplusplus.com/reference/) (https://cplusplus.com/reference/iomanip/)*/

# include <iostream>
# include <assert.h>
using namespace std;

/*
 * Comment this line to enable production version of code!
 */
//#define UNIT_TESTING

struct TriviaNode {
    string question;
    string answer;
    int points;
    TriviaNode *next;
};

class Trivia {
    public:
    int count;
    TriviaNode *head;
    TriviaNode *end;
    Trivia() {
        count = 0;
        head = NULL;
        end = NULL;
    }
};

void initList(Trivia &list) { // Define questions.
    TriviaNode *quest1 = new TriviaNode;
    TriviaNode *quest2 = new TriviaNode;
    TriviaNode *quest3 = new TriviaNode;

    quest1 -> question = "How long was the shortest war on record? (Hint: how many minutes)";
    quest1 -> answer = "38";
    quest1 -> points = 100;
    quest1 -> next = quest2;

    quest2 -> question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
    quest2 -> answer = "Bank of Italy";
    quest2 -> points = 50;
    quest2 -> next = quest3;


    quest3 -> question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
    quest3 -> answer = "Wii Sports";
    quest3 -> points = 20;
    quest3 -> next = NULL;

    list.head = quest1;
    list.end = quest3;
    list.count += 3;
}

int ask(Trivia list, int i, int &bonus) { // Asks a question.
    TriviaNode *question = list.head;

    if (i < 1) { // Checks if you're trying to ask zero questions.
        cout << endl << "Warning - the number of trivia to be asked must equal to or be larger than 1.";
        return 1;
    }

    if (i > list.count) { // Checks if you're trying to ask for more questions than there is.
        cout << endl << "There are only " << list.count << " questions in the list.";
        i = list.count;
        return 1;
    }

    string ans; // Expected answer.
    bonus = 0; // Added points init.

    for (int j = 0; j < i; j++) { // Loops through all the questions.
        cout << endl << "Question: " << question -> question << endl << "Answer: ";
        getline(cin, ans);

        if (question -> answer == ans) {
            cout << "Your answer is correct. You receive " << question -> points << " points.";
            bonus += question -> points; // Adds the correct amount of points to the total.
        }
        else {
            cout << "Your answer is wrong. The correct answer is: " << question -> answer; // oof, lmao.
        }
        cout << endl << "Your Total Points: " << bonus << endl;
        question = question -> next; // Sets up the next question.
    }
    return 0;
}

void addTrivia(Trivia &list) {
    string response;
    do {
        list.count++; //increases the count of questions
        TriviaNode *temp = new TriviaNode;

        cout << "Enter a question: "; // Asks the user to enter a question.
        cin >> temp -> question;

        cout << "Enter an answer: "; // Asks user to enter the answer.
        cin >> temp -> answer;

        cout << "Enter award points: "; // Asks user for point value.
        cin >> temp -> points;

        cout << "Continue? (Yes/No): "; // Should we continue?
        getline(cin.ignore(), response);

        //adds new trivia to list
        list.end -> next = temp;
        list.end = temp;

    }
    while (response.find("No") != string :: npos);
}

void testFunc() { // Initialize test fixtures
    Trivia list;
    int bonus;

    initList(list); // Setup Trivia list

    cout << endl << "Function to test: int ask(Trivia& list, int i, int &bonus)" << endl;

    // Case 1
    cout << "Unit Test Case 1: Ask no questions. The program should give a warning message." << endl;
    assert(1 == ask(list, 0, bonus));
    cout << endl << "Case 1 passed..." << endl;

    // Case 2.1
    cout << endl << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters the incorrect answer." << endl;
    assert(0 == ask(list, 1, bonus));
    assert(0 == bonus);
    cout << "Case 2.1 passed..." << endl;

    // Case 2.2
    cout << endl << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters an correct answer." << endl;
    assert(0 == ask(list, 1, bonus));
    assert(100 == bonus);
    cout << "Case 2.2 passed..." << endl;

    // Case 3.1
    cout << endl << "Unit Test Case 3: Ask all of the questions in the linked list." << endl;
    assert(0 == ask(list, 3, bonus));
    assert(170 == bonus);
    cout << "Case 3.1 passed..." << endl;

    // Case 4
    cout << endl << "Unit Test Case 4: Attempt to ask 5 questions in the linked list. Program should give a warning message." << endl;
    assert (0 == ask(list, 5, bonus));
    cout << "Case 4 passed..." << endl;
}

#ifdef UNIT_TESTING
    void testFunc(void);
#endif

int main() {
    //insert unit testing code
    #ifdef UNIT_TESTING
        cout << "*** This is a debugging version ***\n";
        testFunc();
        cout << "\n*** End of the debugging version ***\n";

     // PROD CODE
    #else
    cout << "*** Welcome to Caleb's trivia quiz ***" << endl;
    Trivia game;
    int bonus;
    initList(game);
    addTrivia(game);

    ask(game, game.count, bonus);

    cout << endl << "*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;

#endif
    return 0;
}