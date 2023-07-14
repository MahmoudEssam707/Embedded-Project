#include <iostream>
#define acceleration 32
using namespace std;

int freefall(int time){
    return (acceleration * (time * time)) / 2;
}

int main() {
    int time;
    cout << "Please enter the time in seconds: ";
    cin >> time;
    int distance = freefall(time);
    cout << "You entered " << time << " in seconds,so the distance is " << distance << " feet." << endl;
    return 0;
}
