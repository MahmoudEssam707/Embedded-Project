#include <iostream>
#include <cmath>
#include <string>
using namespace std;
// if for example : value of 5*5 = 25, then checking of the 25, it should retrieve integer squared value
bool isPerfectSquare(int number){
    if (number < 0) {
        return false;
    }
    int x = sqrt(number);
    return x * x == number;
}
// will print value in the reflected shape : 123 = 321
void reverseDigits(int number){
    string s = to_string(number);
    for(int i=s.length(); i>=0; i--){
        cout << s[i];
    }
    cout << endl;
}
// calculate sum off all values : 123 = 1+2+3 = 6
int calculateSum(int input){
    int sum = 0;
    do {
        sum = sum + input%10;
        input = input/10;
    } while(input!=0);
    return sum;
}

int main() {
    // taking input from user
    int input;
    // simple print
    cout << "Enter an integer: ";
    cin >> input;
    // if the value isn't smaller than 0, then will retrieve perfect square if value it true
    if (isPerfectSquare(input)){
        cout << "It's a perfect square." << endl;
    } else {
        cout << "It's not a perfect square." << endl;
    }
    cout << "The reverse of the input is: ";
    // reversing it
    reverseDigits(input);
    // sum result value
    int value = calculateSum(input);
    cout << "The sum of digits is: " << value << endl;
    return 0;
}
//FUNCTION bool isPerfectSquare(int number)
//if number < 0
//return false
    //END FUNCTION
    //DECLARE x as int = sqrt(number)
    //return x * x == number
//END
// FUNCTION reverseDigits(int number)
    //DECLARE s as string = to_string(number)
    //for i = s.length() from 0 to length of this data by -1
      // DISPLAY s[i];
    //END FUNCTION
    //DISPLAY "\n";
//END
//FUNCTION int calculateSum(int input){
    //DECLARE sum as integar= 0;
    //do
        //COMPUTE sum = sum + input%10
        //COMPUTE input = input/10;
        //END
     // while input!=0
     //END while
    //return sum

    //DECLARE input as integar
    //DISPLAY "Enter an integer: "
   // READ input from user
   //if isPerfectSquare(input)
       //DISPLAY"It's a perfect square."
     //else
        //DISPLAY "It's not a perfect square."
   //END IF
    //DISPLAY "The reverse of the input is: "
     //call reverseDigits(input);
   //DECLARE value as integar = calculateSum(input);
    //DISPLAY "The sum of digits is: " + value
    //return 0



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

