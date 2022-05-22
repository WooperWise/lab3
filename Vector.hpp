#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <sys/types.h>
#include "ComplexNumber.hpp"


template<class T> class MathVector 
{
private:

    struct vector {
        T x;
        T y;
        T z;
    };

    vector vector = {0, 0, 0};

public:

    MathVector () {};

    MathVector (T x, T y, T z) {
        vector.x = x;
        vector.y = y;
        vector.z = z;
    }

    MathVector (MathVector<T> &v) {
        vector.x = v.vector.x;
        vector.y = v.vector.y;
        vector.z = v.vector.z;
    }

    ~MathVector () {
        vector = {0, 0, 0};
    }

    T GetX () {
        return vector.x;
    }

    T GetY () {
        return vector.y;
    }

    T GetZ () {
        return vector.z;
    }

    void Resize (T x, T y, T z) {
        vector = {x, y, z};
    }

    void Print () {
        std::cout << "(" << vector.x << ", " << vector.y
                  << ", " << vector.z << ")\n";
    }

    void operator+(MathVector<T> v) {
        Resize(this->vector.x + v.vector.x, this->vector.y + v.vector.y, this->vector.z + v.vector.z);
    }

    void operator-(MathVector<T> v) {
        Resize(this->vector.x - v.vector.x, this->vector.y - v.vector.y, this->vector.z - v.vector.z);
    }
    
    void operator*(T scal) {
        Resize(this->vector.x * scal, this->vector.y * scal, this->vector.z * scal);
    }

    void operator=(MathVector<T> v) {
        Resize(v.vector.x, v.vector.y, v.vector.z);
    }

    T operator*(MathVector<T> v) {
        return (this->vector.x * v.vector.x) + (this->vector.y * v.vector.y) + (this->vector.z * v.vector.z);
    }

    T NormVector () {
        return (T)(sqrt((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z)));
    }

    void RandomInt () {
        vector.x = rand() % 1000;
        vector.y = rand() % 1000;
        vector.z = rand() % 1000;
    }

    void RandomDouble () {
        vector.x = (double)(rand() % 10000) / 1000;
        vector.y = (double)(rand() % 10000) / 1000;
        vector.z = (double)(rand() % 10000) / 1000;
    }

};

template<class U> class ComplexVector 
{
private:

    struct vector {
        ComplexNum<U> x;
        ComplexNum<U> y;
        ComplexNum<U> z;
    };

    vector vector;

public:

    ComplexVector () {
    };

    ComplexVector (ComplexNum<U> x, ComplexNum<U> y, ComplexNum<U> z) {
        vector.x = x;
        vector.y = y;
        vector.z = z;
    }

    ComplexVector (ComplexVector<U> &v) {
        vector.x = v.vector.x;
        vector.y = v.vector.y;
        vector.z = v.vector.z;
    }

    ~ComplexVector () {
        vector.x.Resize(0, 0);
        vector.y.Resize(0, 0);
        vector.z.Resize(0, 0);
    }

    ComplexNum<U> GetX () {
        return vector.x;
    }

    ComplexNum<U> GetY () {
        return vector.y;
    }

    ComplexNum<U> GetZ () {
        return vector.z;
    }

    void Resize (ComplexNum<U> x, ComplexNum<U> y, ComplexNum<U> z) {
        vector = {x, y, z};
    }

    void Print () {
        std::cout << "("; vector.x.Print(); 
        std::cout << ", "; vector.y.Print();
        std::cout << ", "; vector.z.Print();
        std::cout << ")\n";
    }

    void operator+(ComplexVector<U> v) {
        this->vector.x + v.vector.x;
        this->vector.y + v.vector.y;
        this->vector.z + v.vector.z;
    }

    void operator-(ComplexVector<U> v) {
        this->vector.x - v.vector.x;
        this->vector.y - v.vector.y;
        this->vector.z - v.vector.z;
    }
    
    void operator*(U scal) {
        this->vector.x * scal;
        this->vector.y * scal;
        this->vector.z * scal;
    }

    void operator=(ComplexVector<U> v) {
        Resize(v.vector.x, v.vector.y, v.vector.z);
    }

    ComplexNum<U> MultScalar(ComplexVector<U> v) {
        ComplexVector<U> time_vector(vector.x, vector.y, vector.z);
        time_vector.vector.x * v.vector.x;  time_vector.vector.y * v.vector.y;  time_vector.vector.z * v.vector.z;
        time_vector.vector.x + time_vector.vector.y; time_vector.vector.x + time_vector.vector.z;
        return time_vector.vector.x;
    }

    ComplexNum<U> NormVector () {
        ComplexVector<U> time_vector(vector.x, vector.y, vector.z);
        time_vector.vector.x * time_vector.vector.x;  time_vector.vector.y * time_vector.vector.y;  time_vector.vector.z * time_vector.vector.z;
        time_vector.vector.x + time_vector.vector.y; time_vector.vector.x + time_vector.vector.z;
        time_vector.vector.x.SqrtComplex();
        return time_vector.vector.x;
    }

    void RandomInt () {
        vector.x.RandomInt();
        vector.y.RandomInt(); 
        vector.z.RandomInt();
    }

    void RandomDouble () {
        vector.x.RandomDouble();
        vector.y.RandomDouble(); 
        vector.z.RandomDouble();
    }
};
