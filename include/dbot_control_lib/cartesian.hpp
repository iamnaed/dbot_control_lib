#ifndef DBOT_CONTROL_LIB_CARTESIAN__HPP
#define DBOT_CONTROL_LIB_CARTESIAN__HPP

#include <string>
#include "linear_algebra.hpp"

namespace dbot_control_lib
{

    class Cartesian
    {
    public:
        Cartesian();
        Cartesian(const Translation3d &pos, const Quaterniond &rot);
        Translation3d get_position() const;
        Quaterniond get_rotation() const;
        Isometry3d get_matrix() const;
        std::string to_string() const;

    private:
        Translation3d pos_;
        Quaterniond rot_;
    };

}

#endif // DBOT_CONTROL_LIB_CARTESIAN__HPP