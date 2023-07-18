#include <iostream>

using namespace std;

float velocity_rule(int Tc){
    // retrieving value of velocity
    return 331.3+0.61*Tc;
}

int main() {
    // init the starting temperature, and ending.
    unsigned int start_temp,end_temp;
    // calling for each temperature
    cout << "Please put your start temp : ";
    cin >> start_temp;
    cout << "Please put your end temp : ";
    cin >> end_temp;
    // make the value fixed, and setting 1 digit after point
    cout.setf(ios::fixed);
    cout.precision(1);
    // printing all values between start and end based on that I = start time, and end value till reach end temperature.
    for (int i =start_temp;i<=end_temp;i++){
        cout << "At " << i << " degrees Celsius the velocity of sound is " << velocity_rule(i) << " m/s" <<endl;
    }
    return 0;
}
//FUNCTION velocity_rule(Tc)
//return  331.3+0.61*Tc
//END FUNCTION
//DECLARE start_temp,end_temp as integar
//DISPLAY "Please put your start temp : "
//READ start_temp from user
//call precision(1)
// for i = start_temp to end_temp
//DISPLAY "At " + i + " degrees Celsius the velocity of sound is " + velocity_rule(i) + " m/s\n"
//END FOR
/*
Write a program that allows the user to input a starting and an ending temperature. Within this
temperature range, the program should output the temperature and the corresponding velocity in
1° increments
velocity ≈ 331.3 + 0.61 × Tc
*/

