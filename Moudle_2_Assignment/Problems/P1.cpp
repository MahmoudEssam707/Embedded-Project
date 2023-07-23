// Your First C++ Program
#include <iostream>
#define num_elements 5
using namespace std;
int array_sum_function(int sum[]){
    int sum_result=0;
    for(int number=0; number < num_elements ;number++){
        cout << " " << sum[number];
        sum_result+=sum[number]; 
    }
    return sum_result;
}
int main() {
    int array [num_elements] = {5, 10, 15, 20, 25};
    int sum = array_sum_function(array);
    cout << " , The sum of all this numbers = " << sum << endl;
}

/*
Write a C++ program that initializes an integer array of numbers with 
the following values: 5, 10, 15, 20, 25. Then, using a loop to calculate 
and display the sum of all the numbers in the array
*/
/*
1-declare constant called num_elements with value of 5
2-Creating function called array_sum_function to take input array and retrieving summation
    function will contains
    1.1-varaible called sum_result
    1.2-for loop to trace all array values
        1.1.1-loop will print each value in array to make sure that all values are choose succesfully 
        1.1.2-storing summation of all this values into sum_result
    1.3-returning the value of sum
3-in main function declaring array with size of "num_elements" and put the needed values
4-declaring sum variable and putting it equal to the function passed the array into
5-printing the values of the array and printing sum value
*/