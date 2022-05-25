#pragma once

#include <iostream>
#include "ComplexNumber.hpp"
#include "Sequence.hpp"
#include "Vector.hpp"

template <class T> class MathVectorSequence: Sequence<T>
{
private: 

    MathVector<T>* vector;

public:

    MathVectorSequence () {
        vector = new MathVector<T>;
    }

    MathVectorSequence (T x, T y, T z) {
        vector = new MathVector<T>(x, y, z);
    }

    MathVectorSequence (MathVectorSequence<T> &v) {
        vector = new MathVector<T>(v.GetX(), v.GetY(). v.GetZ());
    }

    ~MathVectorSequence () {
        delete vector;
    }

    T GetX () {
        return this->vector->GetX();
    }

    T GetY () {
        return this->vector->GetY();
    }

    T GetZ () {
        return this->vector->GetZ();
    }

    void Resize (T x, T y, T z) {
        this->vector->Resize(x, y, z);
    }

    void Print () {
        this->vector->Print();
    }

    void Sum(MathVectorSequence<T> v) {
        this->vector + v.vector;
    }

    void MultByScalar(T scal) {
        this->vector * scal;
    }

    void Copy(const MathVectorSequence<T> &v) {
        this->vector = v.vector;
    }

    T MultScalar(const MathVectorSequence<T> &v) {
        return this->vector * v.vector;
    }

    T NormVector () {
        return this->vector->NormVector();
    }

    void RandomInt () {
        this->vector->RandomInt();
    }

    void RandomDouble () {
        this->vector->RandomDouble();
    }
};

template <class U> class ComplexVectorSequence: Sequence<U> 
{
private:

    ComplexVector<U>* vector;

public:

    ComplexVectorSequence () {
        vector = new ComplexVector<U>;
    }

    ComplexVectorSequence (ComplexNum<U> x, ComplexNum<U> y, ComplexNum<U> z) {
        vector = new ComplexVector<U>(x, y, z);
    }

    ComplexVectorSequence (ComplexVectorSequence<U> &v) {
        vector = new ComplexVector<U>(v.GetX(), v.GetY(), v.GetZ());
    }

    ~ComplexVectorSequence () {
        delete vector;
    }

    ComplexNum<U> GetX () {
        return this->vector->GetX();
    }

    ComplexNum<U> GetY () {
        return this->vector->GetY();
    }

    ComplexNum<U> GetZ () {
        return this->vector->GetZ();
    }

    void Resize (ComplexNum<U> x, ComplexNum<U> y, ComplexNum<U> z) {
        this->vector->Resize(x, y, z);
    }

    void Print () {
        this->vector->Print();
    }

    void Sum(ComplexVectorSequence<U> v) {
        this->vector + v.vector;
    }

    void MultByScalar(U scal) {
        this->vector * scal;
    }

    void Copy(ComplexVectorSequence<U> v) {
        this->vector = v.vector;
    }

    ComplexNum<U> MultScalar(ComplexVectorSequence<U> v) {
        this->vector->MultScalar(v.vector);
    }

    ComplexNum<U> NormVector () {
        this->vector->NormVector();
    }

    void RandomInt () {
        this->vector->RandomInt();
    }

    void RandomDouble () {
        this->vector->RandomDouble();
    }
};