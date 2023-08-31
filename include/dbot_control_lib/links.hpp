#ifndef DBOT_CONTROL_LIB_LINKS__HPP
#define DBOT_CONTROL_LIB_LINKS__HPP

#include <string>
#include <vector>
#include <map>

#include "linear_algebra.hpp"
#include "cartesian.hpp"
#include "enums.hpp"

namespace dbot_control_lib
{

    class Links
    {
    public:
        Links(const Cartesian &base,
              const Cartesian &origin,
              const Cartesian &link0,
              const Cartesian &link1,
              const Cartesian &link2,
              const Cartesian &link3,
              const Cartesian &link4,
              const Cartesian &link5,
              const Cartesian &flange,
              const Cartesian &tcp);

        Cartesian get_flange() const;
        Cartesian get_tcp() const;
        Cartesian get_link(const LinkKey &key) const;
        std::vector<Cartesian> get_joint_links() const;
        void set_tcp(const Cartesian &tcp);
        std::string to_string() const;
        
    private:
        std::map<LinkKey, Cartesian> link_map_;
        std::map<LinkKey, std::string> linkkey_to_string_map_;
    };

}

#endif // DBOT_CONTROL_LIB_LINKS__HPP