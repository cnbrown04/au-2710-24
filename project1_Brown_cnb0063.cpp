// Name: Caleb Brown
// Auburn ID: cnb0063
// Filename: project1_Brown_cnb0063.cpp
// To compile on JetBrains: Use the compile button in the top right of the window.

// Sources: stackoverflow.com (https://stackoverflow.com/questions/14765155/how-can-i-easily-format-my-data-table-in-c)
// cplusplus.com (https://cplusplus.com/reference/) (https://cplusplus.com/reference/iomanip/)

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    double monthlyPayment, balance, interestRate, displayInterestRate, intrestSum = 0, intrestCharged;
    int month = 1;

    cout.setf(ios::fixed);    // These lines force currency format in output
    cout.setf(ios::showpoint); // to 2 decimal pts
    cout.precision(2);

    cout << "Loan Amount: "; // Asks for the loan amount.
    cin >> balance; // Collects the loan amount from the user.

    while (balance < 0) { // Total check to see if the loan amount is larger than zero.
        cout << "Please input a loan amount larger than zero." << endl;
        cout << "Loan Amount: ";
        cin >> balance;

        if (balance < 0) {
            break;
        }
    }

    cout << "Interest Rate (% per year): "; // Asks for the interest rate.
    cin >> interestRate; // Collects the interest rate from the user.

    while (interestRate < 0) { // Total check to see if the interest rate is larger than zero.
        cout << "Please input a interest amount larger than zero." << endl;
        cout << "Interest Rate (% per year): ";
        cin >> interestRate;

        if (interestRate < 0) {
            break;
        }
    }

    cout << "Monthly Payments: "; // Asks for the monthly payment.
    cin >> monthlyPayment; // Collects the monthly payment from the user.

    while (monthlyPayment < 0) { // Checks if the monthly payment is greater than zero.
        cout << "Please input a monthly payment larger than zero." << endl;
        cout << "Monthly Payments: ";
        cin >> monthlyPayment;

        if (monthlyPayment < 0) {
            break;
        }
    }

    // 1000 * (1 + (18 / 100) / 12)) - 1000
    // Gets the monthly interest rate as 1.015 (1.5% per month)
    // Multiples by 1000 for the balance + interest.
    // Subtracts the starting balance for the charged interest.
    while (monthlyPayment < ((balance * (1 + (interestRate / 100) / 12)) - balance)) { // Checks if the monthly payment is greater than the interest charged each month.
        cout << "Please input a monthly payment larger than the interest charged per month." << endl;
        cout << "Monthly Payments: ";
        cin >> monthlyPayment;

        if (monthlyPayment < ((balance * (1 + (interestRate / 100) / 12)) - balance)) {
            break;
        }
    }

    // For displaying in the Amortization Table
    displayInterestRate = (interestRate / 12);

    // To get a usable interest rate in calculations.
    while (interestRate >= 1)
        interestRate = interestRate / 100;

    cout << "********************************************************" << endl;
    cout << "          Amortization Table" << endl;
    cout << "********************************************************" << endl;

    // Setting alignment to left and width. Using the ' ' character as a spacer.
    cout << left << setw(7) << setfill(' ') << "Month";
    cout << left << setw(9) << setfill(' ') << "Balance";
    cout << left << setw(12) << setfill(' ') << "Payment";
    cout << left << setw(7) << setfill(' ') << "Rate";
    cout << left << setw(12) << setfill(' ') << "Interest";
    cout << left << setw(9) << setfill(' ') << "Principal";
    cout << endl;

    // Setting alignment to left and width. Using the ' ' character as a spacer.
    cout << left << setw(7) << setfill(' ') << "0";
    cout << left << "$" << setw(8) << setfill(' ') << balance;
    cout << left << setw(12) << setfill(' ') << "N/A";
    cout << left << setw(7) << setfill(' ') << "N/A";
    cout << left << setw(12) << setfill(' ') << "N/A";
    cout << left << setw(9) << setfill(' ') << "N/A";
    cout << endl;

    // Self-explanatory.
    intrestSum = intrestSum + ((balance * (1 + interestRate / 12)) - balance); // Same calculation explained before but with variables and adding it to a rolling variable.
    intrestCharged = ((balance * (1 + interestRate / 12)) - balance); // Same calculation explained before but with variables. Non rolling.
    balance = balance * (1 + interestRate / 12) - monthlyPayment; // Balance calculation.

    // Setting alignment to left and width. Using the ' ' character as a spacer.
    cout << left << setw(7) << setfill(' ') << month;
    cout << left << '$' << setw(8) << setfill(' ') << balance;
    cout << left << '$' << setw(11) << setfill(' ') << monthlyPayment;
    cout << left << setw(7) << setfill(' ') << displayInterestRate;
    cout << left << '$' << setw(11) << setfill(' ') << intrestCharged;
    cout << left << '$' << setw(9) << setfill(' ') << (monthlyPayment - intrestCharged);
    cout << endl;

    // Looping until the end of the loan.
    while (balance > 0) {
        month++; // Month iterator.

        // More calculations explained above.
        if (balance < monthlyPayment) {
            intrestSum = intrestSum + ((balance * (1 + interestRate / 12)) - balance);
            intrestCharged = ((balance * (1 + interestRate / 12)) - balance);
            balance = balance - balance;

            // End of loan.
            cout << left << setw(7) << setfill(' ') << month;
            cout << left << '$' << setw(8) << setfill(' ') << balance;
            cout << left << '$' << setw(11) << setfill(' ') << monthlyPayment;
            cout << left << setw(7) << setfill(' ') << displayInterestRate;
            cout << left << '$' << setw(11) << setfill(' ') << intrestCharged;
            cout << left << '$' << setw(9) << setfill(' ') << (monthlyPayment - intrestCharged);
            cout << endl;
            cout << "**********************************************************" << endl;
            cout << endl;

            cout << "It takes " << month << " months to pay off the loan." << endl;
            cout << "Total interest paid is: $" << intrestSum;
            // End.
            return 0;
        } else {
            // Same calculations.
            intrestSum = intrestSum + ((balance * (1 + interestRate / 12)) - balance);
            intrestCharged = ((balance * (1 + interestRate / 12)) - balance);
            balance = balance * (1 + interestRate / 12) - monthlyPayment;

            cout << left << setw(7) << setfill(' ') << month;
            cout << left << '$' << setw(8) << setfill(' ') << balance;
            cout << left << '$' << setw(11) << setfill(' ') << monthlyPayment;
            cout << left << setw(7) << setfill(' ') << displayInterestRate;
            cout << left << '$' << setw(11) << setfill(' ') << intrestCharged;
            cout << left << '$' << setw(9) << setfill(' ') << (monthlyPayment - intrestCharged);
            cout << endl;

        }

    }
}