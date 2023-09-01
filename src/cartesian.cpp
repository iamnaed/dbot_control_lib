#include "dbot_control_lib/cartesian.hpp"

namespace dbot_control_lib
{

    Cartesian::Cartesian()
    {
        pos_ = Translation3d(0, 0, 0);
        rot_ = Quaterniond::Identity();
    }

    Cartesian::Cartesian(const Translation3d &pos, const Quaterniond &rot) : pos_(pos), rot_(rot)
    {
    }

    Translation3d Cartesian::get_position() const
    {
        return pos_;
    }

    Quaterniond Cartesian::get_rotation() const
    {
        return rot_;
    }

    Isometry3d Cartesian::get_matrix() const
    {    
        Isometry3d affine_pos(pos_);
        Isometry3d affine_rot(rot_);
        return (affine_pos * affine_rot);
    }

    std::string Cartesian::to_string() const
    {
        std::stringstream ss;
        ss << "Cartesian [ ";
        ss << "Translation: {" << pos_.x() << ", " << pos_.y() << ", " << pos_.z() << "}\t";
        //ss << "Translation: {" << pos_.vector().transpose().format(CleanMatrixFormat) << "} \t";
        ss << "Quaternion: {" << rot_ << "} ]\n";
        return ss.str();
    }
}