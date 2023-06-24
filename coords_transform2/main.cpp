#include <iostream>
#include <cmath>

#include <Eigen/Core>
#include <eigen3/Eigen/Geometry>


using namespace std;
using namespace Eigen;

int main() {
    Quaterniond q1(0.35, 0.2, 0.3, 0.1);
    q1.normalize();
    Vector3d v1(0.3, 0.1, 0.1);
    Isometry3d T1 = Isometry3d::Identity();
    T1.rotate(q1.toRotationMatrix());
    T1.pretranslate(v1);

    Quaterniond q2(-0.5, 0.4, -0.1, 0.2);
    q2.normalize();
    Vector3d v2(-0.1, 0.5, 0.3);
    Isometry3d T2 = Isometry3d::Identity();
    T2.rotate(q2.toRotationMatrix());
    T2.pretranslate(v2);

    Vector3d point1(0.5, 0, 0.2);
    Vector3d point2 = T2 * T1.inverse() * point1;
    cout << "point2 = " << point2.transpose() << endl;
}