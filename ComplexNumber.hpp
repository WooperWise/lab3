#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>

template <class T> class ComplexNum 
{
private:

    struct complex {
        T real;
        T imaginary;
    };

    complex item = {0, 0};

public:

    ComplexNum () {}

    ComplexNum (T real, T imaginary) {
        item.real = real;
        item.imaginary = imaginary;
    }

    ComplexNum (ComplexNum<T> &new_item) {
        item.real = new_item.item.real;
        item.imaginary = new_item.item.imaginary;
    }

    ~ComplexNum () {
        item.real = 0;
        item.imaginary = 0;
    }

    T GetReal () {
        return item.real;
    }

    T GetImag () {
        return item.imaginary;
    }

    void operator+(ComplexNum<T> item) {
        Resize(this->item.real + item.item.real, this->item.imaginary + item.item.imaginary);
    }

    void operator-(ComplexNum<T> item) {
        Resize(this->item.real - item.item.real, this->item.imaginary - item.item.imaginary);
    }

    void operator=(const ComplexNum<T> &item) {
        Resize(item.item.real, item.item.imaginary);
    }

    bool operator==(ComplexNum<T> item) {
        if ((item.item.real == this->item.real) && (item.item.imaginary == this->item.imaginary)) {
            return true;
        } else {return false;}
    }

    bool operator!=(const ComplexNum<T> &item) {
        if ((item.item.real != this->item.real) && (item.item.imaginary != this->item.imaginary)) {
            return true;
        } else {return false;}
    }

    void operator* (ComplexNum<T> item) {
        Resize(this->item.real*item.item.real - this->item.imaginary*item.item.imaginary,
                this->item.real*item.item.imaginary + item.item.real*this->item.imaginary);
    }

    void operator* (T scal) {
        Resize(this->item.real*scal, this->item.imaginary*scal);
    }

    void Print () {
        if (item.imaginary == 0) {
            std::cout << item.real;
        }
        if (item.imaginary > 0) {
            std::cout << "(" << item.real << "+" << item.imaginary << "i)";
        } 
        if (item.imaginary < 0) {
            std::cout << "(" << item.real << item.imaginary << "i)";
        }
    }

    void Resize (T real, T imaginary) {
        item.real = real;
        item.imaginary = imaginary;
    }

    void SqrtComplex () {
        T modul = (T)(sqrt(item.real*item.real + item.imaginary*item.imaginary));
        T x = modul * (T)(cos(std::atan(item.imaginary / item.real)));
        T y = modul * (T)(sin(std::atan(item.imaginary / item.real)));
        Resize(x, y);
    }

    void RandomInt () {
        item.real = rand() % 1000;
        item.imaginary = rand() % 1000;
    }

    void RandomDouble () {
        item.real = (double)(rand() % 10000) / 1000;
        item.imaginary = (double)(rand() % 10000) / 1000;
    }

};