#ifndef DBOT_CONTROL_LIB_TRAJECTORY_GENERATOR__HPP
#define DBOT_CONTROL_LIB_TRAJECTORY_GENERATOR__HPP

#include <string>
#include <eigen/eigen.hpp>
#include <array>
#include <vector>

#include "trajectory.hpp"
#include "waypoint.hpp"

namespace dbot_control_lib
{

    /**
     * @brief
     *
     */
    class TrajectoryGenerator
    {
    public:
        /**
         * @brief Blended trajectory
         * https://github.com/ros-planning/moveit/blob/master/moveit_planners/pilz_industrial_motion_planner/doc/MotionBlendAlgorithmDescription.pdf
         *
         * @param type
         * @param waypoints
         * @return Trajectory
         */
        Trajectory generate_blended_trajectory(std::vector<WayPoint> waypoints) const;

        /**
         * @brief
         *
         * @param waypoints
         * @return Trajectory
         */
        Trajectory generate_normal_trajectory(std::vector<WayPoint> waypoints) const;
    };
}

#endif // DBOT_CONTROL_LIB_TRAJECTORY_GENERATOR__HPP