#include "dbot_control_lib/links.hpp"

namespace dbot_control_lib
{

    Links::Links(const Cartesian &base,
                 const Cartesian &origin,
                 const Cartesian &link0,
                 const Cartesian &link1,
                 const Cartesian &link2,
                 const Cartesian &link3,
                 const Cartesian &link4,
                 const Cartesian &link5,
                 const Cartesian &flange,
                 const Cartesian &tcp)
    {
        link_map_[LinkKey::Base] = base;
        link_map_[LinkKey::Origin] = origin;
        link_map_[LinkKey::Link0] = link0;
        link_map_[LinkKey::Link1] = link1;
        link_map_[LinkKey::Link2] = link2;
        link_map_[LinkKey::Link3] = link3;
        link_map_[LinkKey::Link4] = link4;
        link_map_[LinkKey::Link5] = link5;
        link_map_[LinkKey::Flange] = flange;
        link_map_[LinkKey::Tcp] = tcp;

        linkkey_to_string_map_[LinkKey::Base] = "Base";
        linkkey_to_string_map_[LinkKey::Origin] = "Origin";
        linkkey_to_string_map_[LinkKey::Link0] = "Link0";
        linkkey_to_string_map_[LinkKey::Link1] = "Link1";
        linkkey_to_string_map_[LinkKey::Link2] = "Link2";
        linkkey_to_string_map_[LinkKey::Link3] = "Link3";
        linkkey_to_string_map_[LinkKey::Link4] = "Link4";
        linkkey_to_string_map_[LinkKey::Link5] = "Link5";
        linkkey_to_string_map_[LinkKey::Flange] = "Flange";
        linkkey_to_string_map_[LinkKey::Tcp] = "Tcp";
    }

    Cartesian Links::get_flange() const
    {
        return link_map_.at(LinkKey::Flange);
    }

    Cartesian Links::get_tcp() const
    {
        return link_map_.at(LinkKey::Tcp);
    }

    Cartesian Links::get_link(const LinkKey &key) const
    {
        return link_map_.at(key);
    }

    std::vector<Cartesian> Links::get_joint_links() const
    {
        int start = static_cast<int>(LinkKey::Link0);
        int end = static_cast<int>(LinkKey::Tcp);
        std::vector<Cartesian> jls;
        jls.reserve(end - start + 1);
        for(int i = start; i <= end; i++)
        {
            LinkKey lk = static_cast<LinkKey>(i);
            Cartesian c = link_map_.at(lk);
            jls.push_back(c);
        }
        return jls;
    }

    std::string Links::to_string() const
    {
        std::stringstream ss;
        ss << "Links \n";
        for (auto &kv : link_map_)
        {
            auto key = kv.first;
            auto val = kv.second;
            auto key_name = linkkey_to_string_map_.at(key);
            ss << "\t" << key_name << "\n";
            ss << "\t\t" << val.to_string() << "\n";
        }

        return ss.str();
    }
}