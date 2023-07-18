#include <iostream>
using namespace std;
//declare a variable Liter with a double value 0.264172
#define LITER 0.264172
//declare a function milesPerGallon which take 2 integer variables ml and lt and return double value
double milesPerGallon(int ml, int lt);

int main ()
{
    // choose continue or not
    char options;
    // miles and liters
    unsigned int lt, ml;
    do
    {
      // Taking inputs from user
      cout << "Enter the number of Liters of gasoline:";
      cin >> lt;
      cout <<"Enter the number of miles traveled by the car: ";
      cin >> ml;
      cout << "Number of miles per gallon:" << milesPerGallon(ml, lt) << endl;
      cout << "To repeat enter 'R' or enter 'E' to exit:";
      cin >> options;
    } while (options == 'r' || options == 'R');
    return 0;
}
double milesPerGallon(int m, int l)
{
    double gallons;
    gallons = LITER * l;
    return (m/gallons);
}

/*
Define a constant variable LITER with a value 0.264172
Define a function milesPerGallon takes two inputs miles and litters and returns a double value,performing:
a. Declare a double variable gallons
b. Calculate gallons by multiplying LITER with lt
c. Return the value of ml divided by gallons
END FUNCTION
Inside the main function, declare a char variable options
Start a do-while loop that continues while options is equal to 'r' or 'R'
Inside the loop, ask the user to enter the number of liters of gasoline and the number of miles traveled by the car
Call the milesPerGallon function with the entered values and display the result
Ask the user if they want to repeat the calculation or exit the program
If the user chooses to repeat, go back to step 5; otherwise, exit the program
*/
