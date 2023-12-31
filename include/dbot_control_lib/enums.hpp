#ifndef DBOT_CONTROL_LIB_ENUMS__HPP
#define DBOT_CONTROL_LIB_ENUMS__HPP

namespace dbot_control_lib
{

    enum class TrajectoryType
    {
        Joint,
        Cartesian
    };

    enum class LinkKey
    {
        Base = 0,
        Origin,
        Link0,
        Link1,
        Link2,
        Link3,
        Link4,
        Link5,
        Flange,
        Tcp
    };

}

#endif // DBOT_CONTROL_LIB_ENUMS__HPP