#include <iostream>
#include <cmath>
using namespace std;

bool isPerfecSquare(int number){
    long int x;
    if(number>=0){
       x = sqrt(number);
       return(x*x == number);
    }else{
        return false;
    }


}

int main() {
    unsigned int input;
    cin >> input;
    if (isPerfecSquare(input)){
        cout << "It's Perfect square";
    } else {
        cout << "It isn't perfect square";
    }
    return 0;
}