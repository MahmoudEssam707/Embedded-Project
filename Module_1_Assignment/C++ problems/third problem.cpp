#include <iostream>

using namespace std;

void upper(char c){
    // to make upper C
    cout << "   " << c << " " << c << " " << c << endl;
    cout << "  " << c << "    " << c << endl;
}

void lower(char c){
    // the reflection of upper design
    cout << "  " << c << "    " << c << endl;
    cout << "   " << c << " " << c << " " << c << endl;

}

int main() {
    // init for the char user will put
    char c;
    // calling for input
    cout << "Please put the character : ";
    cin >> c ;
    // printing upper value
    upper(c);
    // printing the vertical column of same char, about five times
    for (int i=1;i<=5;i++){
        cout <<" "<< c << endl;
    }
    // printing the reflection of upper value
    lower(c);
    return 0;
}
//Function Upper(c)
//Display " " + "c" + " " + "c" + " " + "c"
//Display " " +"c" +" " + "c"
//END FUNCTION
//Function lower(c)
//Display "  " + "c" + "    " + "c"
//Display "   " + "c" + " " + "c" + " " + "c"
//END FUNCTION
//DECLARE c as CHARACTER
//DISPLAY "Please put the character :"
//READ c from user
//Call UPPER(c)
//for from 1 to 5
//Display " " + "c"
//END FOR
//call LOWER(c)
/*
Write a program that inputs a character
from the keyboard and then outputs a large
block letter “C” composed of that character.
*/

