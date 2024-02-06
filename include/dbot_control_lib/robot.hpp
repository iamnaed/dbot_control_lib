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
        Robot(const std::string &name, const Links &links);
        Cartesian get_forward_kinematics() const;
        Cartesian get_forward_kinematics(const JointAngle &ja) const;
        Cartesian get_forward_kinematics(const JointAngle &ja, const Cartesian &tcp) const;
        std::string get_name() const;
        Cartesian get_tcp() const;
        bool try_get_inverse_kinematics(const Cartesian &target, JointConfiguration &result) const;
        bool try_get_inverse_kinematics(const Cartesian &target, const Cartesian &tcp, JointConfiguration &result) const;
        void set_joints(const JointAngle &ja);
        void set_tcp(const Cartesian &tcp);
        std::string to_string() const;

    private:
        Cartesian solve_wrist(Cartesian target);
        std::vector<double> solve_joint0(Cartesian wrist);
        std::vector<double> solve_joint1(double j0, Cartesian wrist);
        std::vector<double> solve_joint2(double j0, double j1, Cartesian wrist);
        std::vector<double> solve_joint3(double j0, double j1, double j2, double j4, Cartesian wrist);
        std::vector<double> solve_joint4(double j0, double j1, double j2, Cartesian wrist);
        std::vector<double> solve_joint5(double j0, double j1, double j2, double j4, Cartesian wrist);

    private:
        std::string name_;
        Links links_;
        JointAngle ja_;
    };

}

#endif // DBOT_CONTROL_LIB_ROBOT__HPP