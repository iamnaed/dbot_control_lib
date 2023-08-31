#include "dbot_control_lib/trajectory.hpp"

namespace dbot_control_lib
{

    Trajectory::Trajectory()
    {
        type_ = TrajectoryType::Joint;
        trajectory_ = std::vector<TrajectoryPoint>();
    }

    Trajectory::Trajectory(const TrajectoryType &type, const std::vector<TrajectoryPoint> &trajectory) : type_(type), trajectory_(trajectory)
    {
    }

    TrajectoryType Trajectory::get_trajectory_type() const
    {
        return type_;
    }

    std::vector<TrajectoryPoint> Trajectory::get_trajectory() const
    {
        return trajectory_;
    }

}