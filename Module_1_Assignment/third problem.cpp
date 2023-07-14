#include <iostream>

using namespace std;

void upper(char c){
    cout << "   " << c << " " << c << " " << c << endl;
    cout << "  " << c << "    " << c << endl;
}

void lower(char c){
    cout << "  " << c << "    " << c << endl;
    cout << "   " << c << " " << c << " " << c << endl;

}

int main() {
    char c;
    cout << "Please put the character : ";
    cin >> c ;
    upper(c);
    for (int i=1;i<=5;i++){
        cout <<" "<< c << endl;
    }
    lower(c);
    return 0;
}

/*
Write a program that inputs a character
from the keyboard and then outputs a large
block letter “C” composed of that character.
*/

