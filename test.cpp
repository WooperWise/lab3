#include <iostream>
#include "ComplexNumber.hpp"
#include "Vector.hpp"

using namespace std;

int main () {
    ComplexNum<int> aa(5, 2);
    ComplexNum<int> bb(-1, -4);
    ComplexNum<int> cc(-20, 32);


    ComplexVector<int> a(aa, bb, cc);
    ComplexVector<int> b(cc, aa, bb);
    ComplexNum<int> tmp;
    a.Print();
    a * 7;
    a.Print();

   // tmp.Print(); cout << "\n";

    
}