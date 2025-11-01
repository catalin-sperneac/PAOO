#include "MyVector.h"
#include<iostream>
#include<utility>
using namespace std;

MyVector::MyVector(size_t size) : size(size)
{
    cout<<"Constructor: Aloc "<<size<<" elemente"<<endl;
    data = new int[size];
    for(size_t i = 0; i < size; ++i)
    {
        data[i] = 0;
    }
}

MyVector::~MyVector()
{
    cout<<"Destructor: Eliberez memoria"<<endl;
    delete[] data;
}

MyVector::MyVector(const MyVector& other) : size(other.size)
{
    cout<<"Copy constructor: Copiez vectorul"<<endl;
    data = new int[size];
    for(size_t i = 0; i < size; ++i)
    {
        data[i] = other.data[i];
    }
}

MyVector::MyVector(MyVector&& other) noexcept : data(nullptr), size(0)
{
    cout<<"Move constructor: Mut resursele"<<endl;
    data = other.data;
    size = other.size;
    other.data = nullptr;
    other.size = 0;
}

void MyVector::setValue(size_t index, int value)
{
    if(index < size)
    {
        data[index] = value;
    }
}

int MyVector::getValue(size_t index) const
{
    if(index < size)
    {
        return data[index];
    }
    return -1;
}

void MyVector::print() const
{
    for(size_t i = 0; i < size; ++i)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}