// Your First C++ Program
#include <iostream>
#define size 5
using namespace std;
int array_sum_function(int sum[]){
    int sum_result=0;
    for(int number=0; number < size ;number++){
        cout << " " << sum[number];
        sum_result+=sum[number]; 
    }
    return sum_result;
}
int main() {
    int array [size] = {5, 10, 15, 20, 25};
    int sum = array_sum_function(array);
    cout << " , The sum of all this numbers = " << sum << endl;
}

/*
Write a C++ program that initializes an integer array of numbers with 
the following values: 5, 10, 15, 20, 25. Then, using a loop to calculate 
and display the sum of all the numbers in the array
*/
/*
1-declare constant called size with value of 5
2-declare variable called sum to store the sum of array
3-declare array with size of declared size in first point and putting from 5 to 25 by increasing 5 as sequentially
4-Starting for loop with i starting from 0, and smaller than the size of array, and increasing by 1
5-printing each value in array to make sure it's right in calling
6-will store summation of all this values in sum variable
7-printing the result of sum
*/