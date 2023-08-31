#ifndef DBOT_CONTROL_LIB_TRAJECTORY__HPP
#define DBOT_CONTROL_LIB_TRAJECTORY__HPP

#include <string>
#include <eigen/eigen.hpp>
#include <array>
#include <vector>

#include "trajectory_point.hpp"
#include "enums.hpp"

namespace dbot_control_lib
{

    /**
     * @brief
     *
     */
    class Trajectory
    {
    public:
        Trajectory();
        Trajectory(const TrajectoryType &type, const std::vector<TrajectoryPoint> &trajectory);
        TrajectoryType get_trajectory_type() const;
        std::vector<TrajectoryPoint> get_trajectory() const;

    private:
        TrajectoryType type_;
        std::vector<TrajectoryPoint> trajectory_;
    };

}

#endif // DBOT_CONTROL_LIB_TRAJECTORY__HPP