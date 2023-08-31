#ifndef DBOT_CONTROL_LIB_TRAJECTORY_POINT__HPP
#define DBOT_CONTROL_LIB_TRAJECTORY_POINT__HPP

#include <string>
#include <array>
#include <vector>

#include "linear_algebra.hpp"

namespace dbot_control_lib
{

    /**
     * @brief
     *
     */
    class TrajectoryPoint
    {
    public:
        double time;
        Array6d point;
    };

}

#endif // DBOT_CONTROL_LIB_TRAJECTORY_POINT__HPP