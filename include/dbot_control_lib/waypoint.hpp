#ifndef DBOT_CONTROL_LIB_WAYPOINT__HPP
#define DBOT_CONTROL_LIB_WAYPOINT__HPP

#include <string>
#include <array>
#include <vector>

#include "linear_algebra.hpp"

namespace dbot_control_lib {

    class WayPoint
    {
    public:
        Array6d point;
    };
    
}

#endif // DBOT_CONTROL_LIB_WAYPOINT__HPP