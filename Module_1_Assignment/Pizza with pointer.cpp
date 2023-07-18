//import libraries
#include <iostream>
#include <cmath>
#define PI 3.14
using namespace std;

double pizza_1_diametar;
double pizza_1_price;
double pizza_1_R;
double pizza_1_area;
double pizza_1_pricePERarea;

double pizza_2_diametar;
double pizza_2_price;
double pizza_2_R;
double pizza_2_area;
double pizza_2_pricePERarea;

void input(double* pizza_1_diametar,double* pizza_1_price ,double* pizza_2_diametar,double* pizza_2_price){
    cout<<"what is diametar of pizza 1 in cm ?"<<endl;
    cin>>*pizza_1_diametar;
    cout<<"what is price of pizza 1 in $ ?"<<endl;
    cin>>*pizza_1_price;
    cout<<"what is diametar of pizza 2 in cm ?"<<endl;
    cin>>*pizza_2_diametar;
    cout<<"what is price of pizza 2 in $ ?"<<endl;
    cin>>*pizza_2_price;
}
void calc_R (double* pizza_R,double pizza_diametar){
    *pizza_R=0.5* pizza_diametar;
}
void calc_area(double* pizza_area, double pizza_R){
    *pizza_area=M_PI*pizza_R*pizza_R;
}
void calc_pricePERarea(double* pizza_pPa , double pizza_price, double Pizza_area){
    *pizza_pPa=pizza_price/Pizza_area;
}
void compare(double pizza_1_pricePERarea, double pizza_2_pricePERarea ){
    if(pizza_1_pricePERarea>pizza_2_pricePERarea){
        cout<<" pizza 2 is better "<<endl;
    }
    else{
        cout<<"pizza 1 is better "<<endl;
    }
}
//main function
int main() {
    input(&pizza_1_diametar,&pizza_1_price,&pizza_2_diametar,&pizza_2_price);

    calc_R(&pizza_1_R,pizza_1_diametar);
    calc_R(&pizza_2_R,pizza_2_diametar);

    calc_area(&pizza_1_area,pizza_1_R);
    calc_area(&pizza_2_area,pizza_2_R);

    calc_pricePERarea(&pizza_1_pricePERarea,pizza_1_price,pizza_1_area);
    calc_pricePERarea(&pizza_2_pricePERarea,pizza_2_price,pizza_2_area);

    compare(pizza_1_pricePERarea,pizza_2_pricePERarea);


}
