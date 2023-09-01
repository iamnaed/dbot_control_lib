#ifndef DBOT_CONTROL_LIB_LINEAR_ALGEBRA__HPP
#define DBOT_CONTROL_LIB_LINEAR_ALGEBRA__HPP

#include <array>
#include <Eigen/Dense>
#include <Eigen/Geometry>

namespace dbot_control_lib
{
    /**
     * @brief
     */
    typedef std::array<double, 6> Array6d;

    /**
     * @brief
     *
     */
    typedef Eigen::Matrix<double, 6, 1> Vector6d;

    /**
     * @brief
     *
     */
    typedef Eigen::Quaterniond Quaterniond;

    /**
     * @brief
     *
     */
    typedef Eigen::AngleAxisd AngleAxisd;

    /**
     * @brief
     *
     */
    typedef Eigen::Matrix4d Matrix4d;

    /**
     * @brief
     *
     */
    typedef Eigen::Vector3d Vector3d;

    /**
     * @brief
     *
     */
    typedef Eigen::Isometry3d Isometry3d;

    /**
     * @brief
     *
     */
    typedef Eigen::Translation3d Translation3d;

    /**
     * @brief
     *
     * @param x
     * @param y
     * @param z
     * @return Quaterniond
     */
    inline Quaterniond euler_zyx_to_quaternion(double x, double y, double z)
    {
        Quaterniond q;
        q = AngleAxisd(z, Vector3d::UnitZ()) * AngleAxisd(y, Vector3d::UnitY()) * AngleAxisd(x, Vector3d::UnitX());
        return q;
    }

    /**
     * @brief
     *
     * @param euler
     * @return Quaterniond
     */
    inline Quaterniond euler_zyx_to_quaternion(Vector3d euler)
    {
        return euler_zyx_to_quaternion(euler.x(), euler.y(), euler.z());
    }

    inline Eigen::IOFormat CleanMatrixFormat(4, 0, ", ", "\n", "[", "]");
}

#endif // DBOT_CONTROL_LIB_LINEAR_ALGEBRA__HPP