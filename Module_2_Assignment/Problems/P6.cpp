#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n < 0) {
        return -1; // Factorial is not defined for negative numbers
    }
    if (n == 0) {
        return 1; // Base case: factorial of 0 is 1
    }
    // will perform same function "Recursive "
    return n * factorial(n - 1);
}

int main() {
    int num;
    // here will take input from user
    cout << "Enter a number: ";
    cin >> num;
    // storing variable of factorial in fact
    int fact = factorial(num);
    if (fact == -1) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "Factorial of " << num << " is: " << fact << endl;
    }

    return 0;
}
