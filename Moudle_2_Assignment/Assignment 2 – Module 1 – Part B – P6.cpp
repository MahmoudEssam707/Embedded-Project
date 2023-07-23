#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n < 0) {
        return -1; // Factorial is not defined for negative numbers
    }

    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int fact = factorial(num);
    if (fact == -1) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "Factorial of " << num << " is: " << fact << endl;
    }

    return 0;
}
