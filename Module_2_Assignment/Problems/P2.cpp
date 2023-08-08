#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the average of elements in an array
double average(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return double (sum) / n;
}

int main() {
    int n;
    cout << "Enter the number of elements: " << endl;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i + 1 << ": " << endl;
        cin >> arr[i];
    }

    double av = average(arr, n);
    cout << "Average = " << av << endl;

    return 0;
}
