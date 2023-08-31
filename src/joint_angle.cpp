#include "dbot_control_lib/joint_angle.hpp"

namespace dbot_control_lib
{

    JointAngle::JointAngle()
    {
        joints_ << 0.0, 0.0, 0.0, 0.0, 0.0, 0.0;
    }

    JointAngle::JointAngle(const Vector6d &joints) : joints_(joints)
    {
    }

    Vector6d JointAngle::to_column_vector() const
    {
        return joints_;
    }

    std::string JointAngle::to_string() const
    {
        std::stringstream ss;
        ss << "JointAngle: {" << joints_ << "} \n";
        return ss.str();
    }

    double JointAngle::operator()(size_t idx) const
    {
        return joints_(idx);
    }

    double JointAngle::operator[](size_t idx) const
    {
        return joints_(idx);
    }
}