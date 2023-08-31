#ifndef DBOT_CONTROL_LIB_JOINT_ANGLE__HPP
#define DBOT_CONTROL_LIB_JOINT_ANGLE__HPP

#include <string>

#include "linear_algebra.hpp"

namespace dbot_control_lib
{

    class JointAngle
    {
    public:
        JointAngle();
        JointAngle(const Vector6d &joints);
        Vector6d to_column_vector() const;
        std::string to_string() const;
        double operator()(size_t idx) const;
        double operator[](size_t idx) const;
    private:
        Vector6d joints_;
    };

}

#endif // DBOT_CONTROL_LIB_JOINT_ANGLE__HPP