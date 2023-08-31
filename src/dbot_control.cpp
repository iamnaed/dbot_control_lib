#include "dbot_control_lib/dbot_control.hpp"

namespace dbot_control_lib
{

    std::string DbotControl::debug()
    {
        return std::string{"dbot_control_lib DBOT_CONTROL DEBUG. . ."};
    }

    std::string DbotControl::to_string()
    {
        Cartesian c;
        return c.to_string();
    }
}