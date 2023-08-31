#ifndef DBOT_CONTROL_LIB_JOINT_CONFIGURATION__HPP
#define DBOT_CONTROL_LIB_JOINT_CONFIGURATION__HPP

#include <string>

#include "linear_algebra.hpp"
#include "joint_angle.hpp"

namespace dbot_control_lib
{

    class JointConfiguration
    {
    public:
        JointConfiguration() = default;
        JointConfiguration(const std::vector<JointAngle> &joints);
        std::string to_string() const;
    private:
        std::vector<JointAngle> joint_angles_ = {};
    };

}

#endif // DBOT_CONTROL_LIB_JOINT_CONFIGURATION__HPP