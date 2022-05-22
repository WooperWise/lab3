#include <iostream>
#include <ctime>
#include "ComplexNumber.hpp"
#include "Vector.hpp"
#include "Print.hpp"

using namespace std;

int main() {
    int exit1 = 1, exit2 = 1;
    char command1 = 0, command2 = 0;
    char flag = 0;
    Print p;

    srand(time(NULL));
    
    p.Hello();
    while (exit1) {
        p.Choose(); cin >> command1;

        switch (command1) {
        case '1':{
            flag = 'N'; p.Enter(); cin >> flag;
            MathVector<int> vector1;
            MathVector<int> vector2;
            int vect[3] = {0, 0, 0}, scal = 0, item = 0;
            if (flag == 'Y') {
                p.Vect1(); cin >> vect[0] >> vect[1] >> vect[2];
                vector1.Resize(vect[0], vect[1], vect[2]);
                p.Vect2(); cin >> vect[0] >> vect[1] >> vect[2];
                vector2.Resize(vect[0], vect[1], vect[2]);
            } else { 
                if (flag == 'N') {
                    vector1.RandomInt(); vector2.RandomInt();                
                } else throw runtime_error("You entered wrong.");
            }
            p.Good();

            exit2 = 1;
            while (exit2) {
                p.Info(); cin >> command2;

                switch (command2) {
                case 'i': {
                    p.Menue();
                    break;
                } case '0': {
                    vector1.RandomInt(); vector2.RandomInt();
                    p.Good();
                    break;
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
                    item = vector1 * vector2;
                    cout << item << "\n";
                    break;
                } case '8': {
                    item = vector1.NormVector();
                    cout << item << "\n";
                    break;
                } case '9': {
                    exit2 = 0;
                    break;
                } case 'P': {
                    vector1.Print(); vector2.Print();
                }}
            }
            break;
        } case '2': {
            flag = 'N'; p.Enter();cin >> flag;
            MathVector<double> vector1;
            MathVector<double> vector2;
            double vect[3] = {0, 0, 0}, scal = 0, item = 0;
            if (flag == 'Y') {
                p.Vect1(); cin >> vect[0] >> vect[1] >> vect[2];
                vector1.Resize(vect[0], vect[1], vect[2]);
                p.Vect2(); cin >> vect[0] >> vect[1] >> vect[2];
                vector2.Resize(vect[0], vect[1], vect[2]);
            } else { 
                if (flag == 'N') {
                    vector1.RandomDouble(); vector2.RandomDouble();                
                } else throw runtime_error("You entered wrong.");
            }
            p.Good();

            exit2 = 1;
            while (exit2) {
                p.Info(); cin >> command2;

                switch (command2) {
                case 'i': {
                    p.Menue();
                    break;
                } case '0': {
                    vector1.RandomDouble(), vector2.RandomDouble();
                    p.Good();
                    break;
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
                    item = vector1 * vector2;
                    cout << item << "\n";
                    break;
                } case '8': {
                    item = vector1.NormVector();
                    cout << item << "\n";
                    break;
                } case '9': {
                    exit2 = 0;
                    break;
                } case 'P': {
                    vector1.Print(); vector2.Print();
                }}
            }
            break;
        } case '3': {
            flag = 'N'; p.Enter(); cin >> flag;
            int scal = 0;
            ComplexNum<int> item;
            ComplexVector<int> vector1;
            ComplexVector<int> vector2;
            int real = 0, imaginary = 0;
            ComplexNum<int> X, Y, Z;
            if (flag == 'Y') {
                p.CmplxVector1();
                p.CmplxNmbrX(); cin >> real >> imaginary; X.Resize(real, imaginary);
                p.CmplxNmbrY(); cin >> real >> imaginary; Y.Resize(real, imaginary);
                p.CmplxNmbrZ(); cin >> real >> imaginary; Z.Resize(real, imaginary);
                vector1.Resize(X, Y, Z);
                p.CmplxVector2();
                p.CmplxNmbrX(); cin >> real >> imaginary; X.Resize(real, imaginary);
                p.CmplxNmbrY(); cin >> real >> imaginary; Y.Resize(real, imaginary);
                p.CmplxNmbrZ(); cin >> real >> imaginary; Z.Resize(real, imaginary);
                vector2.Resize(X, Y, Z);
            } else { 
                if (flag == 'N') {
                    vector1.RandomInt(); vector2.RandomInt();
                } else throw runtime_error("You entered wrong.");
            }
            p.Good();

            exit2 = 1;
            while (exit2) {
                p.Info(); cin >> command2;

                switch (command2) {
                case 'i': {
                    p.Menue();
                    break;
                } case '0': {
                   vector1.RandomInt(), vector2.RandomInt();
                   p.Good();
                   break; 
                } case '1': {
                    vector1.GetX().Print(); cout << "\n";
                    break;
                } case '2': {
                    vector1.GetY().Print(); cout << "\n";
                    break;
                } case '3': {
                    vector1.GetZ().Print(); cout << "\n";
                    break;
                } case '4': {
                    p.VectNew(); 
                    p.CmplxNmbrX(); cin >> real >> imaginary; X.Resize(real, imaginary);
                    p.CmplxNmbrY(); cin >> real >> imaginary; Y.Resize(real, imaginary);
                    p.CmplxNmbrZ(); cin >> real >> imaginary; Z.Resize(real, imaginary);
                    vector1.Resize(X, Y, Z);
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
                    item = vector1.MultScalar(vector2);
                    item.Print(); cout << "\n";
                    break;
                } case '8': {
                    item = vector1.NormVector();
                    item.Print(); cout << "\n"; 
                    break;
                } case '9': {
                    exit2 = 0;
                    break;
                } case 'P': {
                    vector1.Print(); vector2.Print();
                }}
            }
            break;
        } case '4': {
            flag = 'N'; p.Enter(); cin >> flag;
            double scal = 0;
            ComplexNum<double> item;
            ComplexVector<double> vector1;
            ComplexVector<double> vector2;
            double real = 0, imaginary = 0;
            ComplexNum<double> X, Y, Z;
            if (flag == 'Y') {
                p.CmplxVector1();
                p.CmplxNmbrX(); cin >> real >> imaginary; X.Resize(real, imaginary);
                p.CmplxNmbrY(); cin >> real >> imaginary; Y.Resize(real, imaginary);
                p.CmplxNmbrZ(); cin >> real >> imaginary; Z.Resize(real, imaginary);
                vector1.Resize(X, Y, Z);
                p.CmplxVector2();
                p.CmplxNmbrX(); cin >> real >> imaginary; X.Resize(real, imaginary);
                p.CmplxNmbrY(); cin >> real >> imaginary; Y.Resize(real, imaginary);
                p.CmplxNmbrZ(); cin >> real >> imaginary; Z.Resize(real, imaginary);
                vector2.Resize(X, Y, Z);
            } else { 
                if (flag == 'N') {
                    vector1.RandomDouble(); vector2.RandomDouble();
                } else throw runtime_error("You entered wrong.");
            }
            p.Good();

            exit2 = 1;
            while (exit2) {
                p.Info(); cin >> command2;

                switch (command2) {
                case 'i': {
                    p.Menue();
                    break;
                } case '0': {
                   vector1.RandomDouble(), vector2.RandomDouble();
                   p.Good();
                   break; 
                } case '1': {
                    vector1.GetX().Print(); cout << "\n";
                    break;
                } case '2': {
                    vector1.GetY().Print(); cout << "\n";
                    break;
                } case '3': {
                    vector1.GetZ().Print(); cout << "\n";
                    break;
                } case '4': {
                    p.VectNew(); 
                    p.CmplxNmbrX(); cin >> real >> imaginary; X.Resize(real, imaginary);
                    p.CmplxNmbrY(); cin >> real >> imaginary; Y.Resize(real, imaginary);
                    p.CmplxNmbrZ(); cin >> real >> imaginary; Z.Resize(real, imaginary);
                    vector1.Resize(X, Y, Z);
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
                    item = vector1.MultScalar(vector2);
                    item.Print(); cout << "\n";
                    break;
                } case '8': {
                    item = vector1.NormVector();
                    item.Print(); cout << "\n"; 
                    break;
                } case '9': {
                    exit2 = 0;
                    break;
                } case 'P': {
                    vector1.Print(); vector2.Print();
                }}
            }
            break;
        } case '5': {
            exit1 = 0;
            break;
        }}
    }

    return 0;
}