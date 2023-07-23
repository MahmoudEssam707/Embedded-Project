// Your First C++ Program
#include <iostream>
using namespace std;
int main() {
    int size=5;
    int sum=0;
    int array [size] = {5, 10, 15, 20, 25};
    for(int number=0; number < size ;number++){
        cout << " " << array[number];
        sum+=array[number];
    }
    cout << " , The sum of all this numbers = " << sum << endl;
}

/*
Write a C++ program that initializes an integer array of numbers with 
the following values: 5, 10, 15, 20, 25. Then, using a loop to calculate 
and display the sum of all the numbers in the array
*/