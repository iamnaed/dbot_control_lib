#ifndef DBOT_CONTROL_LIB_ROBOT__HPP
#define DBOT_CONTROL_LIB_ROBOT__HPP

#include <string>

#include "linear_algebra.hpp"
#include "cartesian.hpp"
#include "joint_angle.hpp"
#include "links.hpp"
#include "joint_configuration.hpp"

namespace dbot_control_lib
{

    class Robot
    {
    public:
        Robot(const std::string &name, const Links &links, const Cartesian &tcp);
        Cartesian get_forward_kinematics() const;
        Cartesian get_forward_kinematics(const JointAngle &ja) const;
        Cartesian get_forward_kinematics(const JointAngle &ja, const Cartesian &tcp) const;
        std::string get_name() const;
        Cartesian get_tcp() const;
        bool try_get_inverse_kinematics(const Cartesian &target, JointConfiguration &result) const;
        bool try_get_inverse_kinematics(const Cartesian &target, const Cartesian &tcp, JointConfiguration &result) const;
        void set_joints(const JointAngle &ja);
        std::string to_string() const;

    private:
        std::string name_;
        Links links_;
        JointAngle ja_;
    };

}

#endif // DBOT_CONTROL_LIB_ROBOT__HPP