#include "dbot_control_lib/robot_builder.hpp"

namespace dbot_control_lib
{

    Robot RobotBuilder::build_spherical_wrist_robot(const std::string &name) const
    {
        Cartesian base;
        Cartesian origin;
        Cartesian j0;
        Cartesian j1;
        Cartesian j2;
        Cartesian j3;
        Cartesian j4;
        Cartesian j5;
        Cartesian flange;
        Cartesian tcp;

        Links links(base, origin, j0, j1, j2, j3, j4, j5, flange, tcp);
        return Robot(name, links);
    }

    Robot RobotBuilder::build_non_spherical_wrist_robot(const std::string &name) const
    {
        Cartesian base;
        Cartesian origin;
        Cartesian j0;
        Cartesian j1;
        Cartesian j2;
        Cartesian j3;
        Cartesian j4;
        Cartesian j5;
        Cartesian flange;
        Cartesian tcp;

        Links links(base, origin, j0, j1, j2, j3, j4, j5, flange, tcp);
        return Robot(name, links);
    }

    Robot RobotBuilder::build_dbot_robot() const
    {
        std::string name{"dbot"};

        Translation3d base_pos = {0.0, 0.0, 0.0};
        Quaterniond base_rot = Quaterniond::Identity();

        Translation3d origin_pos = {0.0, 0.0, 0.242};
        Quaterniond origin_rot = Quaterniond::Identity();

        Translation3d j0_pos = {0.0, 0.0, 0.0};
        Quaterniond j0_rot = Quaterniond::Identity();

        Translation3d j1_pos = {0.0, 0.1075, 0.0};
        Quaterniond j1_rot = euler_zyx_to_quaternion(M_PI_2, 0.0, 0.0);

        Translation3d j2_pos = {0.0, 0.350, 0.0};
        Quaterniond j2_rot = Quaterniond::Identity();

        Translation3d j3_pos = {0.0, 0.300, 0.1075};
        Quaterniond j3_rot = Quaterniond::Identity();

        Translation3d j4_pos = {0.0, 0.0, -0.125};
        Quaterniond j4_rot = euler_zyx_to_quaternion(-M_PI_2, 0.0, 0.0);

        Translation3d j5_pos = {0.0, 0.0, 0.125};
        Quaterniond j5_rot = euler_zyx_to_quaternion(M_PI_2, 0.0, 0.0);

        Translation3d flange_pos = {0.0, 0.0, 0.0565};
        Quaterniond flange_rot = Quaterniond::Identity();

        Translation3d tcp_pos = {0.0, 0.0, 0.0};
        Quaterniond tcp_rot = Quaterniond::Identity();

        Cartesian base(base_pos, base_rot);
        Cartesian origin(origin_pos, origin_rot);
        Cartesian j0(j0_pos, j0_rot);
        Cartesian j1(j1_pos, j1_rot);
        Cartesian j2(j2_pos, j2_rot);
        Cartesian j3(j3_pos, j3_rot);
        Cartesian j4(j4_pos, j4_rot);
        Cartesian j5(j5_pos, j5_rot);
        Cartesian flange(flange_pos, flange_rot);
        Cartesian tcp(tcp_pos, tcp_rot);

        Links links(base, origin, j0, j1, j2, j3, j4, j5, flange, tcp);
        return Robot(name, links);
    }

    /**
     * @brief
     *
     * @return std::string
     */
    std::string RobotBuilder::to_string() const
    {
        return "RobotBuilder";
    }
}