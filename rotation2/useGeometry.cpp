#include <iostream>
#include <cmath>

#include <Eigen/Core>
#include <eigen3/Eigen/Geometry>


using namespace std;
using namespace Eigen;

int main(int argc, char **argv) {
    // 3D rotation matrix using Matrix3d or Matrix3f
    Matrix3d rotation_matrix = Matrix3d::Identity();

    // Rotation vector uses AngleAxis
    AngleAxisd rotation_vector(M_PI/4, Vector3d(0, 0, 1)); // Rotate 45 degrees a long Z axis
    std::cout.precision(3);
    cout << "Rotation vector (in matrix form) = \n " << rotation_vector.matrix() << endl; // Convert to matrix
    cout << "Rotation vector axis = \n " << rotation_vector.axis() << endl; // Convert to matrix
    cout << "Rotation vector angle = \n " << rotation_vector.angle() << endl; // Convert to matrix
    cout << "Rotation matrix = \n " << rotation_matrix.matrix() << endl; // Convert to matrix

    // Use AngleAxis to convert to rotation matrix
    rotation_matrix = rotation_vector.toRotationMatrix();
    cout << "Rotation matrix = \n " << rotation_matrix.matrix() << endl; // Convert to matrix

    // Transform coordinates
    Vector3d v(1, 1, 2);
    //Vector3d v_rotated = v * rotation_vector;
    Vector3d v_rotated = rotation_vector * v;
    cout << "(1, 0, 0) after rotation = " << v_rotated.transpose() << endl;

    // Can use rotation matrix
    v_rotated = rotation_matrix * v;
    cout << "(1, 0, 0) after rotation = " << v_rotated.transpose() << endl;

    // Euler angle
    Vector3d euler_angles = rotation_vector.matrix().eulerAngles(0, 1, 2); // XYZ order
    cout << "roll pitch yaw = " << euler_angles.transpose() << endl;
    euler_angles = rotation_matrix.eulerAngles(2, 1, 0);
    cout << "yaw pitch roll =  " << euler_angles.transpose() << endl;

    // Euclidean transform matrix
    Isometry3d T = Isometry3d::Identity(); // 4x4 matrix
    T.rotate(rotation_vector);
    T.pretranslate(Vector3d(1,3,4));
    cout << "Transform matrix = \n " << T.matrix() << endl;

    // Use transform matrix for coordinate transformation
    Vector3d v_transformed = T * v;
    Vector3d v_transformed_equivalent = rotation_matrix * v + Vector3d(1, 3, 4);
    cout << "v_transformed = \n " << v_transformed.transpose() << endl;
    cout << "v_transformed_equivalent = \n " << v_transformed_equivalent.transpose() << endl;

    // Affine transform
    Affine3d affine_matrix = Affine3d::Identity();
    affine_matrix.rotate(rotation_vector);
    affine_matrix.pretranslate(Vector3d(1, 3, 4));
    affine_matrix.scale(2.0);
    cout << "Affine matrix = \n " << affine_matrix.matrix() << endl;
    // Perspective transform
    Projective3d projective_matrix = Projective3d::Identity();

    // Quaternion
    Quaterniond q = Quaterniond(rotation_vector);
    cout << "quaternion = " << q.coeffs().transpose() << endl; // (x, y, z, w)
    q = Quaterniond(rotation_matrix);
    cout << "quaternion = " << q.coeffs().transpose() << endl; // (x, y, z, w)
    // Use quaternion to rotate
    v_rotated = q * v; // Equivalent to qvq^{-1}
    cout << "(1, 0, 0) after rotation = " << v_rotated.transpose() << endl;
    // To use qvq^{-1}, use inverse and convert v to qUaternion
    Quaterniond v_quaternion(0, v.x(), v.y(), v.z());
    Quaterniond v_quaternion_rotated = q * v_quaternion * q.inverse();
    cout << "q * v * q^{-1} = " << v_quaternion_rotated.coeffs().transpose() << endl;
}