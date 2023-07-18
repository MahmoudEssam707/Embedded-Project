#include <iostream>
#define PI 3.14159
#define cm_per_inch 2.54
using namespace std;
// global variables
double radius , area;
// will take from user Price and diameter which is double of radius
double price_pizza(double price, double diameter_inch) {
    radius =  diameter_inch / 2.0 * cm_per_inch;
    area = PI * radius * radius;
    return price / area;
}
int main()
{
    // taking Small and large values
    int small_Diameter, large_Diameter;
    double small_Price,large_Price,small_Price_Per_Cmsqu,large_Price_Per_Cmsqu;
    // calling for each diameter and price for pizzas
    cout << "Enter diameter small pizza with(inches): ";
    cin >> small_Diameter;
    cout << "Enter price of small pizza: ";
    cin >> small_Price;
    cout << "Enter diameter large pizza with(inches): ";
    cin >> large_Diameter;
    cout << "Enter price of large pizza: ";
    cin >> large_Price;
    // Performing Price Per CmSq for small and large
    small_Price_Per_Cmsqu = price_pizza(small_Price, small_Diameter);
    large_Price_Per_Cmsqu = price_pizza(large_Price, large_Diameter);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    // checking of which is better
    cout << "The value of small pizza price per CmSq :" << small_Price_Per_Cmsqu << ", And for greater one : " << large_Price_Per_Cmsqu << endl;
    if (large_Price_Per_Cmsqu < small_Price_Per_Cmsqu) {
        cout << "Large pizza is a better ." << endl;
    } else {
        cout << "Small pizza is a better ." << endl;
    }
    return 0;
}

/*
making global constants as PI for 3.14, and converting from inchs to CM with 2.54
declare function price_of_pizza with diametar_inch and price as inputs
 compute radius = diameter_inch / 2.0 * cm_per_inch
 compute area = pi*r^2
return price per cm^2
END FUNCTION
read inches of small pizza and price from user
read inches of big pizza and price from user
compute price small , large
if(large<small)
  print(large is better)
else
  print(small is better)
end if
*/
