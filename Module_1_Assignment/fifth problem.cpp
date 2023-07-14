#include <iostream>
#include <cmath>
using namespace std;
int main() {
    // inputs
    unsigned int account_balance, interest, total_with_interest, minimum_payment;
    char repeat;
    do {
        // Taking input from user
        cout << "Please enter your account balance: $";
        cin >> account_balance;
        // calculating interest
        if (account_balance <= 1000) {
            interest = round(account_balance * 0.015);
        } else {
            interest = round(1000 * 0.015 + (account_balance - 1000) * 0.01);
        }
        // Calculate the total amount with interest
        total_with_interest = account_balance + interest;

        // Calculate the minimum payment
        if (total_with_interest <= 10) {
            minimum_payment = total_with_interest;
        } else {
            minimum_payment = max(10, int(round(total_with_interest * 0.1)));
        }
        // Results
        cout << "Account balance: $" << account_balance << endl;
        cout << "Interest charged: $" << interest << endl;
        cout << "Total amount due with interest: $" << total_with_interest << endl;
        cout << "Minimum payment: $" << minimum_payment << endl;
        // Ask the user if they want to repeat the calculation
        cout << "Do you want to calculate again? (Y/N) ";
        cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}
/*
Write a program to compute the interest due, total amount due, and the
minimum payment for a revolving credit account. The program accepts the
account balance as input, then adds on the interest to get the total amount
due. The rate schedules are the following: The interest is 1.5 percent on the
first $1,000 and 1 percent on any amount over that. The minimum payment
is the total amount due if that is $10 or less; otherwise, it is $10 or 10
percent of the total amount owed, whichever is larger. Your program
should include a loop that lets the user repeat this calculation until the user
says she or he is done.
*/

