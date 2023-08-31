#include "dbot_control_lib/joint_configuration.hpp"

namespace dbot_control_lib
{

    JointConfiguration::JointConfiguration(const std::vector<JointAngle> &joints) : joint_angles_(joints)
    {
    }

    std::string JointConfiguration::to_string() const
    {
        std::stringstream ss;
        ss << "JointConfiguration\n";
        for (auto &ja : joint_angles_)
        {
            ss << "\t" << ja.to_string() << " \n";
        }

        return ss.str();
    }

}