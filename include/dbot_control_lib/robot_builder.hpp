#ifndef DBOT_CONTROL_LIB_ROBOT_BUILDER__HPP
#define DBOT_CONTROL_LIB_ROBOT_BUILDER__HPP

#include <string>

#include "robot.hpp"

namespace dbot_control_lib
{

    class RobotBuilder
    {
    public:
        RobotBuilder() = default;
        Robot build_spherical_wrist_robot(const std::string &name) const;
        Robot build_non_spherical_wrist_robot(const std::string &name) const;
        Robot build_dbot_robot() const;
        std::string to_string() const;

    private:
    };

}

#endif // DBOT_CONTROL_LIB_ROBOT_BUILDER__HPP