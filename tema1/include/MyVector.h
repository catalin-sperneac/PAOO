#pragma once
#include<iostream>

class MyVector
{
    private:
        int* data;
        size_t size;

    public:
        //Constructor
        MyVector(size_t size);
        //Destructor
        ~MyVector();
        //Copy constructor
        MyVector(const MyVector& other);
        //Move constructor
        MyVector(MyVector&& other) noexcept;
        //Getter si setter (incapsulare)
        void setValue(size_t index, int value);
        int getValue(size_t index) const;
        //Afisare
        void print() const;
};