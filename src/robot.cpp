#include "dbot_control_lib/robot.hpp"

namespace dbot_control_lib
{

    /**
     * @brief Construct a new Robot:: Robot object
     *
     * @param name
     * @param links
     * @param tcp
     */
    Robot::Robot(const std::string &name, const Links &links, const Cartesian &tcp) : name_(name), links_(links)
    {
    }

    /**
     * @brief
     *
     * @return Cartesian
     */
    Cartesian Robot::get_forward_kinematics() const
    {
        return get_forward_kinematics(ja_, links_.get_tcp());
    }

    /**
     * @brief
     *
     * @param ja
     * @return Cartesian
     */
    Cartesian Robot::get_forward_kinematics(const JointAngle &ja) const
    {
        return get_forward_kinematics(ja, links_.get_tcp());
    }

    /**
     * @brief
     *
     * @param ja
     * @param tcp
     * @return Cartesian
     */
    Cartesian Robot::get_forward_kinematics(const JointAngle &ja, const Cartesian &tcp) const
    {
        // Data
        auto jls = links_.get_joint_links();
        auto transform_mat = Isometry3d::Identity();

        // Calculate transformation in joints
        for (size_t i = 0; i < jls.size(); i++)
        {
            // Link
            Isometry3d link_mat = jls[i].get_matrix();

            // Joint
            double joint = ja[i];
            AngleAxisd aa(joint, Vector3d::UnitZ());
            Isometry3d joint_mat(aa);

            // Update transform
            transform_mat = transform_mat * (link_mat * joint_mat);
        }

        // Calculate transformation in flange and tcp
        Isometry3d flange_mat = links_.get_flange().get_matrix();
        Isometry3d tcp_mat = tcp.get_matrix();
        transform_mat = transform_mat * (flange_mat * tcp_mat);

        // Final
        Translation3d t(transform_mat.translation());
        Quaterniond r(transform_mat.rotation());
        return Cartesian(t, r);
    }

    /**
     * @brief
     *
     * @return std::string
     */
    std::string Robot::get_name() const
    {
        return name_;
    }

    /**
     * @brief
     *
     * @return Cartesian
     */
    Cartesian Robot::get_tcp() const
    {
        return links_.get_tcp();
    }

    /**
     * @brief
     *
     * @param target
     * @param result
     * @return true
     * @return false
     */
    bool Robot::try_get_inverse_kinematics(const Cartesian &target, JointConfiguration &result) const
    {
        return try_get_inverse_kinematics(target, links_.get_tcp(), result);
    }

    /**
     * @brief
     *
     * @param target
     * @param result
     * @param tcp
     * @return true
     * @return false
     */
    bool Robot::try_get_inverse_kinematics(const Cartesian &target, const Cartesian &tcp, JointConfiguration &result) const
    {
    }

    /**
     * @brief
     *
     * @param ja
     */
    void Robot::set_joints(const JointAngle &ja)
    {
        ja_ = ja;
    }

    /**
     * @brief
     *
     * @return std::string
     */
    std::string Robot::to_string() const
    {
        std::stringstream ss;
        ss << "Robot: {" << name_ << "} \n";
        return ss.str();
    }
}