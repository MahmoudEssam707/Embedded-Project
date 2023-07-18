// Bubble sort in C++

#include <iostream>
using namespace std;

// perform bubble sort
void bubbleSort(int arr[], int ssize) {
  // loop to access each array element
  for (int step = 0; step < ssize; step++) {
    // loop to compare array elements
    for (int i = 0; i < ssize - step -1; i++) {
      // compare two adjacent elements
      // change > to < to sort in descending order
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
  }
}

int main() {
  int data[] = {-2, 45, 0, 11, -9};

  // find array's length
  int ssize = sizeof(data) / sizeof(data[0]);

  bubbleSort(data, ssize);

  cout << "Sorted Array in Ascending Order:\n";
  for (int i = 0; i < ssize; i++) {
    cout << "  " << data[i];
  }
  cout << "\n";
}
/*
function bubbleSort(arr, ssize)
    for each step in the data after performing 1 swap
        for each element in the array
            compare it with its next element
            if it is greater than the next element
                swap the elements
            end if
        end for
    end for
end function

function main()
    initialize an array of numbers
    calculate the size of the array
    sort the array using bubble sort
    print the sorted array
end function
*/
