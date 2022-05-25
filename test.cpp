#include <iostream>
#include "ComplexNumber.hpp"
#include "Vector.hpp"
#include <cmath>

using namespace std;

int main () {
    int int_scalar = 10, int_item = 0; 
    double double_scalar = 10, double_item = 0;
    ComplexNum<int> cmplx_int_item(0, 0), ans_int_item1(-38, 3), ans_int_item2(0, 0);
    ComplexNum<double> cmplx_double_item(0, 0), ans_dounle_item;

    MathVector<int> int_vector1(1, -2, 3), 
                    int_vector2(-4, 5, -6);

    MathVector<double> double_vector1(1.1, -2.1, 3.1), 
                       double_vector2(-4.2, 5.2, -6.2);

    ComplexNum<int> int_X1(1, -1), int_Y1(-2, 1), int_Z1(3, -1), 
                    int_X2(-4, -2), int_Y2(5, 2), int_Z2(-6, -2),
                    int_X(-3, -3), int_Y(3, 3), int_Z(-3, -3),
                    int_X_scal(10, -10), int_Y_scal(-20, 10), int_Z_scal(30, -10); 
    ComplexVector<int> cmplx_int_vector1(int_X1, int_Y1, int_Z1), 
                       cmplx_int_vector2(int_X2, int_Y2, int_Z2);
    
    ComplexNum<double>  double_X1(1.1, -1.1), double_Y1(-2.1, 1.1), double_Z1(3.1, -1.1), 
                        double_X2(-4.2, -2.2), double_Y2(5.2, 2.2), double_Z2(-6.2, -2.2),
                        double_X(-3.1, -3.3), double_Y(3.1, 3.3), double_Z(-3.1, -3.3),
                        double_X_scal(11, -11), double_Y_scal(-21, 11), double_Z_scal(31, -11);
    ComplexVector<double> cmplx_double_vector1(double_X1, double_Y1, double_Z1), 
                          cmplx_double_vector2(double_X2, double_Y2, double_Z2);

    cout << "Starting test int vector.\n";
    if (int_vector1.GetX() != 1) throw runtime_error("GetX test failed.\n");
    if (int_vector1.GetY() != -2) throw runtime_error("GetY test failed.\n");
    if (int_vector1.GetZ() != 3) throw runtime_error("GetZ test failed.\n");
    int_vector1 + int_vector2;
    if ((int_vector1.GetX() != -3 ) && (int_vector1.GetY() != 3) && (int_vector1.GetZ() != -3)) throw runtime_error("Sum test failed.\n");
    int_vector1.Resize(1, -2, 3);
    int_vector1 * 10;
    if ((int_vector1.GetX() != 10 ) && (int_vector1.GetY() != -20) && (int_vector1.GetZ() != 30))
        throw runtime_error("Mult by scalar test failed.\n");
    int_vector1.Resize(1, -2, 3);
    int_item = (int_vector1 * int_vector2);
    if (int_item != -32) throw runtime_error("Scalar mult test failed.\n");
    int_item = int_vector1.NormVector();
    if (int_item != 3) throw runtime_error("Norm vector test failed.\n");
    cout << "Test int vector passed!\n\n";

    cout << "Starting double vector.\n";
    if (double_vector1.GetX() != 1.1) throw runtime_error("GetX test failed.\n");
    if (double_vector1.GetY() != -2.1) throw runtime_error("GetY test failed.\n");
    if (double_vector1.GetZ() != 3.1) throw runtime_error("GetZ test failed.\n");
    double_vector1 + double_vector2;
    if ((double_vector1.GetX() != -3.1) && (double_vector1.GetY() != 3.1) && (double_vector1.GetZ() != -3.1)) throw runtime_error("Sum test failed.\n");
    double_vector1.Resize(1.1, -2.1, 3.1);
    double_vector1 * 10;
    if ((double_vector1.GetX() != 11 ) && (double_vector1.GetY() != -21) && (double_vector1.GetZ() != 31))
        throw runtime_error("Mult by scalar test failed.\n");
    double_vector1.Resize(1.1, -2.1, 3.1);
    double_item = (double_vector1 * double_vector2);
    if (fabs(double_item + 34.8) > 0.05) throw runtime_error("Scalar mult test failed.\n");
    double_item = double_vector1.NormVector();
    if (fabs(double_item - 3.9) > 0.05) throw runtime_error("Norm vector test failed.\n");
    cout << "Test double vector passed!\n\n";

    cout << "Starting test complex int vector.\n";
    if (cmplx_int_vector1.GetX() != int_X1) throw runtime_error("GetX test failed.\n");
    if (cmplx_int_vector1.GetY() != int_Y1) throw runtime_error("GetY test failed.\n");
    if (cmplx_int_vector1.GetZ() != int_Z1) throw runtime_error("GetZ test failed.\n");
    cmplx_int_vector1 + cmplx_int_vector2;
    if ((cmplx_int_vector1.GetX() != int_X) && (cmplx_int_vector1.GetY() != int_Y) && (cmplx_int_vector1.GetZ() != int_Z)) 
        throw runtime_error("Sum test failed.\n");
    cmplx_int_vector1.Resize(int_X1, int_Y1, int_Z1);
    cmplx_int_vector1 * 10;
    if ((cmplx_int_vector1.GetX() != int_X_scal) && (cmplx_int_vector1.GetY() != int_Y_scal) && (cmplx_int_vector1.GetZ() != int_Z_scal))
        throw runtime_error("Mult by scalar test failed.\n");
    cmplx_int_vector1.Resize(int_X1, int_Y1, int_Z1);
    cmplx_int_item = cmplx_int_vector1.MultScalar(cmplx_int_vector2);
    if (cmplx_int_item != ans_int_item1) throw runtime_error("Scalar mult test failed.\n");
    cmplx_int_item = cmplx_int_vector1.NormVector();
    if (cmplx_int_item != ans_int_item2) throw runtime_error("Norm vector test failed.\n");
    cout << "Test complex int vector passed!\n\n";

    cout << "Starting test complex double vector.\n";
    if (cmplx_double_vector1.GetX() != double_X1) throw runtime_error("GetX test failed.\n");
    if (cmplx_double_vector1.GetY() != double_Y1) throw runtime_error("GetY test failed.\n");
    if (cmplx_double_vector1.GetZ() != double_Z1) throw runtime_error("GetZ test failed.\n");
    cmplx_double_vector1 + cmplx_double_vector2;
    if ((cmplx_double_vector1.GetX() != double_X) && (cmplx_double_vector1.GetY() != double_Y) && (cmplx_double_vector1.GetZ() != double_Z)) 
        throw runtime_error("Sum test failed.\n");
    cmplx_double_vector1.Resize(double_X1, double_Y1, double_Z1);
    cmplx_double_vector1 * 10;
    if ((cmplx_double_vector1.GetX() != double_X_scal) && 
        (cmplx_double_vector1.GetY() != double_Y_scal) && (cmplx_double_vector1.GetZ() != double_Z_scal))
        throw runtime_error("Mult by scalar test failed.\n");
    cmplx_double_vector1.Resize(double_X1, double_Y1, double_Z1);
    cmplx_double_item = cmplx_double_vector1.MultScalar(cmplx_double_vector2);
    if ((fabs(cmplx_double_item.GetReal() + 42.02) > 0.05) && (fabs(cmplx_double_item.GetImag() - 3.3) > 0.05)) 
        throw runtime_error("Scalar mult test failed.\n");
    cmplx_double_item = cmplx_double_vector1.NormVector();
    if ((fabs(cmplx_double_item.GetReal() - 11.6) > 0.05) && (fabs(cmplx_double_item.GetImag() + 13.86) > 0.05)) 
        throw runtime_error("Norm vector test failed.\n");
    cout << "Test complex double vector passed!\n\n";

   return 0;    
}