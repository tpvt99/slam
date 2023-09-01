#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <sophus/se3.hpp>

using namespace std;
using namespace Eigen;

int main(int argc, char **argv) {
    // Rotation matrix with 90 degrees along Z axis
    Vector3d v(1, 2, 1);
    v.normalize();
    Matrix3d R = AngleAxisd(M_PI / 2, v).toRotationMatrix();
    // Convert to quaternion
    Quaterniond q(R);

    cout << "Rotation matrix: " << endl << R << endl;
    cout << "Quaternion: " << endl << q.coeffs() << endl;
    cout << "Rotation vector: " << endl << q.vec() << endl;

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

    // Now I turn to logarithmic mapping using raw formula instead .log()
    double trace = R.trace();
    EigenSolver<Matrix3d> eigenSolver(R);
    cout << "Eigen vectors: " << endl << eigenSolver.eigenvectors() << endl;
    cout << "Eigen values: " << endl << eigenSolver.eigenvalues() << endl;
    cout << "Trace of R: " << trace << endl;
    // Get the eigen vector corresponding to eigenvalue of 1
    Vector3d eigenVector;
    for (int i = 0; i < 3; i++) {
        if (abs(eigenSolver.eigenvalues()[i].real() - 1) < 1e-6) {
            eigenVector = eigenSolver.eigenvectors().col(i).real();
            break;
        }
    }
    double theta = acos((trace - 1) / 2);
    cout << "so3 = " << theta * eigenVector.transpose() << endl; // this should be the same as .log()
    // From so3 to SO3 by exponential model
    Sophus::SO3d matrix = Sophus::SO3d::exp(so3);
    Eigen::Matrix3d rotation_matrix = matrix.matrix();
    cout << "SO3 from so3 = " << endl << rotation_matrix << endl;

    // Purturbation model
    Vector3d update_sol3(1e-4, 0, 0); // this is a small update
    Sophus::SO3d update_SO3 = Sophus::SO3d::exp(update_sol3) * SO3_R;
    cout << "SO3 update = " << "\n" << update_SO3.matrix() << endl;

    cout << "*********************" << endl;

    Eigen::Vector3d v1(1, 3, 5);
    Eigen::Vector3d v2(2, 3, 4);

    double dotprod = v1.dot(v2);
    cout << dotprod << endl;

    // OUter product
    Eigen::Matrix3d outerprod = v1 * v2.transpose();
    cout << outerprod << endl;
    // Cross product
    Eigen::Vector3d crossprod = v1.cross(v2); 
    cout << crossprod << endl;
    // Cross product using skew-symmetric matrix
    Eigen::Vector3d crossprod2 = Sophus::SO3d::hat(v1) * v2;
    cout << crossprod2 << endl;
}