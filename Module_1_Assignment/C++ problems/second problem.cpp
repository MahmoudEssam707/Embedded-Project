#include <iostream>
#define acceleration 32
using namespace std;

int freefall(int time){
    // retrieve value of distance based on the rule of free fall.
    return (acceleration * (time * time)) / 2;
}

int main() {
    // Inin time
    unsigned int time;
    // Calling for input time
    cout << "Please enter the time in seconds: ";
    // getting value of time
    cin >> time;
    // Declaring distance and performing freefall rule
    int distance = freefall(time);
    // Printing the result
    cout << "You entered " << time << " in seconds,so the distance is " << distance << " feet." << endl;
    // return if success
    return 0;
}

// FUNCTION freefall(time)
// return (acceleration * (time * time)) / 2)
//END FUNCTION
//DECLARE time as integar
//DISPLAY "Please enter the time in seconds: "
//READ time from user
//COMPUTE distance=call freefall(time)
//DISPLAY "You entered ", time, " seconds, so the distance is ", distance, " feet."
// return 0
//END FUNCTION
