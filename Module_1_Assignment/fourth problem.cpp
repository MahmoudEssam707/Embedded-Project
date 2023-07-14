#include <iostream>

using namespace std;

float velocity_rule(int Tc){
    return 331.3+0.61*Tc;
}

int main() {
    int start_temp,end_temp;
    cout << "Please put your start temp : ";
    cin >> start_temp;
    cout << "Please put your end temp : ";
    cin >> end_temp;
    cout.precision(1);
    for (int i =start_temp;i<=end_temp;i++){
        cout << "At " << i << " degrees Celsius the velocity of sound is " << velocity_rule(i) << " m/s" <<endl;
    }

    return 0;
}

/*
Write a program that allows the user to input a starting and an ending temperature. Within this
temperature range, the program should output the temperature and the corresponding velocity in
1° increments
velocity ≈ 331.3 + 0.61 × Tc
*/

/*
1- INTIALIZE start_temp and end_temp
