#include <iostream>

using namespace std;

#include <ctime>
// Eigen core
#include "Eigen/Core"
// Algebraic operation
// #include <eigen3/Eigen/Dense> this works
#include "Eigen/Dense" // To work, must include the header in cmake file

using namespace Eigen;

#define MATRIX_SIZE 50

int main(int argc, char **argv) {
    // Declare a 2x3 float matrix
    Matrix<float, 2, 3> matrix_23;

    // Declare a 3x1 float vector in 2 ways
    Vector3d v_3d;
    Matrix<float, 3, 1> vd_3d;

    // Matrix 3d
    Matrix3d matrix_33 = Matrix3d::Zero();

    // Input data
    matrix_23 << 1, 2, 3, 4, 5, 6;

    // OUtput
    cout << "matrix_23: " << matrix_23.transpose() << endl;

    // Access elements
    cout << "Another way of printing: " << endl;
    for (int i = 0; i<2; i++) {
        for (int j = 0; j<3; j++) {
            cout << matrix_23(i, j) << "\t";
        }
        cout << endl;
    }

    // Multiply matrix and vector
    v_3d << 3, 2, 1;
    vd_3d << 4, 5, 6;

    Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
    cout << "[1, 2, 3; 4, 5, 6] * [3, 2, 1] = " << result << endl;

    Matrix<float, 2, 1> result2 = matrix_23 * vd_3d;
    cout << "[1, 2, 3; 4, 5, 6] * [3, 2, 1] = " << result2 << endl;

    //Matrix operations
    matrix_33 = Matrix3d::Random(); // Random matrix
    cout << matrix_33 << endl;
    cout << "transpose: " << matrix_33.transpose() << endl;
    cout << "det: " << matrix_33.determinant() << endl;

    // Solving equation

}