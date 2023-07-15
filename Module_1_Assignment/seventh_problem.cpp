#include <iostream>
#include <cmath>
#define G 6.673*pow(10,-8)
using namespace std;
double m1;
double m2;
double d;
void input(double* m1,double* m2, double* d){
    cout<<"what is mass of object 1 in grams?"<<endl;
    cin>>*m1;
    cout<<"what is mass of object 2 in grams?"<<endl;
    cin>>*m2;
    cout<<"what is distance between the two objects in centimeters?"<<endl;
    cin>>*d;

}
double Force(double m1 , double m2 , double d){
    return (G*m1*m2)/(d*d);
}
void result(double m1 , double m2 , double d, double f){
    cout<<"Gravity G is "<<G<<" N"<<endl;
    cout<<"mass of object 1 in grams is "<<m1<<" G"<<endl;
    cout<<"mass of object 2 in grams is  "<<m2<<" G"<<endl;
    cout<<"distance between the two objects in centimeters is "<<d<<" CM"<<endl;
    cout<<"Force between the two objects in dynes is "<<f<<" dyens"<<endl;
    cout<<"where one dynes = ((g*cm)/(sec*sec))"<<endl;


}
int main() {
    input(&m1,&m2,&d);
    double forcee=Force(m1,m2,d);
    result(m1,m2,d,forcee);
}

