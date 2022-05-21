#include <iostream>
#include "ComplexNumber.hpp"
#include "Vector.hpp"
#include "Print.hpp"

using namespace std;

int main() {
    int exit1 = 1, exit2 = 1;
    char command1 = 0, command2 = 0;
    Print p;
    
    p.Hello();
    while (exit1) {
        p.Choose(); cin >> command1;

        switch (command1) {
        case '1':{
            int vect[3] = {0, 0, 0}, scal = 0, item = 0;
            p.Vect1(); cin >> vect[0] >> vect[1] >> vect[2];
            MathVector<int> vector1(vect[0], vect[1], vect[2]);
            p.Vect2(); cin >> vect[0] >> vect[1] >> vect[2];
            MathVector<int> vector2(vect[0], vect[1], vect[2]);
            p.Good();

            exit2 = 1;
            while (exit2) {
                p.Info(); cin >> command2;

                switch (command2) {
                case 'i': {
                    p.Menue();
                    break;
                } case '0': {
                    
                } case '1': {
                    cout << vector1.GetX() << "\n";
                    break;
                } case '2': {
                    cout << vector1.GetY() << "\n";
                    break;
                } case '3': {
                    cout << vector1.GetZ() << "\n";
                    break;
                } case '4': {
                    p.VectNew(); cin >> vect[0] >> vect[1] >> vect[2];
                    vector1.Resize(vect[0], vect[1], vect[2]);
                    p.Good();
                    break;
                } case '5': {
                    vector1 + vector2;
                    vector1.Print();
                    break;
                } case '6': {
                    p.Scal(); cin >> scal;
                    vector1 * scal;
                    vector1.Print();
                    break;
                } case '7': {
                    vector1 * vector2;
                    vector1.Print();
                    break;
                } case '8': {
                    item = vector1.NormVector();
                    cout << item << "\n";
                    break;
                } case '9': {
                    exit2 = 0;
                    break;
                } case 'P': {
                    vector1.Print();
                }}
            }
            break;
        } case '2': {

            break;
        } case '3': {

            break;
        } case '4': {
            exit1 = 0;
            break;
        }}
    }

    return 0;
}