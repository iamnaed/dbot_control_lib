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
}

#endif // DBOT_CONTROL_LIB_LINEAR_ALGEBRA__HPP