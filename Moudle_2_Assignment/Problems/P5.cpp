#include <iostream>
using namespace std;
// function to return sum of elements in an array of length n
int sum(int arr[], int n)
{
// initialize the integer variable sum     
    int sum = 0;
 
// for loop to Iterate through all elements and add them to sum
    for (int i = 0; i < n; i++)
        sum += arr[i];
// return sum of all values
    return sum;
}
// Declare main function
int main()
{
// Declare an array of integer numbers    
    int arr[] = { 12, 3, 4, 15 };
// Declare an integer variable n whose value is length of array 
const int n = 4;
// Display "sum of given array is" and sum of all elements in array arr of length n    
    cout << "Sum of given array is " << sum(arr, n);
    return 0;
}
