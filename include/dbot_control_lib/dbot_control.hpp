#ifndef DBOT_CONTROL_LIB_DBOT_CONTROL__HPP
#define DBOT_CONTROL_LIB_DBOT_CONTROL__HPP

#include <string>
#include <sstream>

#include "cartesian.hpp"

namespace dbot_control_lib
{

    /**
     * @brief
     *
     */
    class DbotControl
    {
    public:
        /**
         * @brief
         *
         * @return std::string
         */
        std::string debug();

        /**
         * @brief
         *
         * @return std::string
         */
        std::string to_string();

    private:
    };
}

#endif // DBOT_CONTROL_LIB_DBOT_CONTROL__HPP