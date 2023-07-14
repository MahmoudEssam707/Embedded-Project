#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool isPerfectSquare(int number){
    if (number < 0) {
        return false;
    }
    int x = sqrt(number);
    return x * x == number;
}

void reverseDigits(int number){
    string s = to_string(number);
    for(int i=s.length(); i>=0; i--){
        cout << s[i];
    }
    cout << endl;
}

int calculateSum(int input){
    int sum = 0;
    do {
        sum = sum + input%10;
        input = input/10;
    } while(input!=0);
    return sum;
}

int main() {
    int input;
    cout << "Enter an integer: ";
    cin >> input;
    if (isPerfectSquare(input)){
        cout << "It's a perfect square." << endl;
    } else {
        cout << "It's not a perfect square." << endl;
    }
    cout << "The reverse of the input is: ";
    reverseDigits(input);
    int value = calculateSum(input);
    cout << "The sum of digits is: " << value << endl;
    return 0;
}
/*
Write a program that takes a positive integer as input from the user and performs the following
tasks:
1. Function isPerfectSquare(): Implement a function that checks whether a number is a perfect
square. The function should return true if the number is a perfect square, and false otherwise.
2. Function reverseDigits(): Implement a function that reverses the digits of a given number. For
example, if the input is 12345, the function should return 54321.
3. Function calculateSum(): Implement a function that calculates the sum of all digits in a given
number.
4. In the main() function, prompt the user to enter a positive integer. Perform the following tasks:
5. Check if the number is a perfect square using the isPerfectSquare() function. Display an
appropriate message.
6. Reverse the digits of the number using the reverseDigits() function. Display the reversed
number.
7. Calculate the sum of all digits in the number using the calculateSum() function. Display the
sum.
*/

