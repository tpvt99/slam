#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <sophus/se3.hpp>

using namespace std;
using namespace Eigen;

int main(int argc, char **argv) {
    // Rotation matrix with 90 degrees along Z axis
    Matrix3d R = AngleAxisd(M_PI / 2, Vector3d(0, 0, 1)).toRotationMatrix();
    // Convert to quaternion
    Quaterniond q(R);

    cout << "Rotation matrix: " << endl << R << endl;
    cout << "Quaternion: " << endl << q.coeffs() << endl;

    // Sophus SO3d
    Sophus::SO3d SO3_R(R); // Construct from rotation matrix
    Sophus::SO3d SO3_q(q); // Construct from quaternion

    cout << "SO(3) from matrix: " << endl << SO3_R.matrix() << endl;
    cout << "SO(3) from quaternion: " << endl << SO3_q.matrix() << endl;

    // Use logarithmic map to get Lie algebra
    Vector3d so3 = SO3_R.log();
    cout << "so3 = " << so3.transpose() << endl;
    // Hat to turn tuo skew-symmetric matrix
    Matrix3d so3_hat = Sophus::SO3d::hat(so3);
    cout << "so3 hat = " << endl << so3_hat << endl;
    // Vee to turn skew-symmetric matrix to vector
    cout << "so3 hat vee = " << Sophus::SO3d::vee(so3_hat).transpose() << endl;
}