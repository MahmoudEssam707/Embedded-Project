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
