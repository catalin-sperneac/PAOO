#include "MyVector.h"
using namespace std;

MyVector createVector() 
{
    MyVector temp(3);
    temp.setValue(0,10);
    temp.setValue(1,20);
    temp.setValue(2,30);
    return temp; //testam move constructor
}

int main()
{
    cout<<"Creez v1"<<endl;
    MyVector v1(5);
    v1.setValue(0,42);
    v1.print();
    
    cout<<"Creez v2 ca o copie a lui v1"<<endl;
    MyVector v2 = v1;
    v2.print();

    cout<<"Creez v3 folosind move constructor"<<endl;
    MyVector v3 = createVector();
    v3.print();

    return 0;
}