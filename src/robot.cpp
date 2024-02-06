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
    Robot::Robot(const std::string &name, const Links &links) : name_(name), links_(links)
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
        (void)target;
        (void)tcp;
        (void)result;


        return false;
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
     * @param ja
     */
    void Robot::set_tcp(const Cartesian &tcp)
    {
        links_.set_tcp(tcp);
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
        ss << links_.to_string() << "\n";
        return ss.str();
    }

    /**
     * @brief 
     * 
     * @param target 
     * @return Cartesian 
     */
    Cartesian Robot::solve_wrist(Cartesian target)
    {
        return Cartesian();
    }

    /**
     * @brief 
     * 
     * @param wrist 
     * @return std::vector<double> 
     */
    std::vector<double> Robot::solve_joint0(Cartesian wrist)
    {
        return std::vector<double>();
    }

    /**
     * @brief 
     * 
     * @param j0 
     * @param wrist 
     * @return std::vector<double> 
     */
    std::vector<double> Robot::solve_joint1(double j0, Cartesian wrist)
    {
        return std::vector<double>();
    }

    /**
     * @brief 
     * 
     * @param j0 
     * @param j1 
     * @param wrist 
     * @return std::vector<double> 
     */
    std::vector<double> Robot::solve_joint2(double j0, double j1, Cartesian wrist)
    {
        return std::vector<double>();
    }

    /**
     * @brief 
     * 
     * @param j0 
     * @param j1 
     * @param j2 
     * @param j4 
     * @param wrist 
     * @return std::vector<double> 
     */
    std::vector<double> Robot::solve_joint3(double j0, double j1, double j2, double j4, Cartesian wrist)
    {
        return std::vector<double>();
    }

    /**
     * @brief 
     * 
     * @param j0 
     * @param j1 
     * @param j2 
     * @param wrist 
     * @return std::vector<double> 
     */
    std::vector<double> Robot::solve_joint4(double j0, double j1, double j2, Cartesian wrist)
    {
        return std::vector<double>();
    }

    /**
     * @brief 
     * 
     * @param j0 
     * @param j1 
     * @param j2 
     * @param j4 
     * @param wrist 
     * @return std::vector<double> 
     */
    std::vector<double> Robot::solve_joint5(double j0, double j1, double j2, double j4, Cartesian wrist)
    {
        return std::vector<double>();
    }
}
