#include <iostream>
#include <algorithm>
using namespace std;

int maxProduct(int arr[], int n) {
    int max_product = arr[0] * arr[1] * arr[2];
    // if size is less than 3, no triplet exists
    if (n < 3)
        return -1;
    // will contain max product
    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
                max_product = max(max_product, arr[i] * arr[j] * arr[k]);

    return max_product;
}

// Driver program to test above functions
int main() {
    int arr[] = { 10, 3, 5, 6, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_prod = maxProduct(arr, n);

    if (max_prod == -1)
        cout << "No triplet exists";
    else
        cout << "Maximum product is " << max_prod;

    return 0;
}

/*
Initialize function max_of_Product with parameters arr[] and n
2. If n is less than 3, return -1
END IF
Initialize max_product as INT_MIN
Loop through the array with index i from 0 up to n-2(for loop with index "i" iterates through each element in the array from the beginning up to the third-to-last element.)
    a. Loop through the array with index j from i+1 up to n-1(for loop with index "j" iterates through each element in the array from "i+1" up to the second-to-last element.)
        i. Loop through the array with index k from j+1 up to n(for loop with index "k" iterates through each element in the array from "j+1" up to the last element.)
End for
            1. Find the product of arr[i], arr[j], and arr[k]
            2. If the product is greater than max_product, update max_product with the product
Return max_product
END FUNCTION
Declare an array arr with values {10, 3, 5, 6, 20} and size n as the size of the array divided by the size of the first element
8. Call the max_of_Product function with parameters arr[] and n and store the result in max
9. If max is equal to -1, print "No Triplet Exists"
10. Else, print "Maximum product is " concatenated with max.
END IF
*/
