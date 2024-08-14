/**
 * @date      8/27/20
 * @copyright (c) Semodia GmbH (2020). All rights reserved.
 */

#ifndef SEMODIA_CONTROLENGINE_NATIVE_PATHTOOL_HPP
#define SEMODIA_CONTROLENGINE_NATIVE_PATHTOOL_HPP

#pragma once

#include <vector>
#include <string>

namespace semodia::controlengine::native::osal {
    /**
     * @class PathTool
     * @brief A helper-class for dissecting, merging and manipulating paths
     */
    class PathTool {
    public:
        virtual ~PathTool() = default;

        /**
         * @return the path separator used by the API (note that this is not necessarily the separator used by the OS!)
         */
        inline static std::string getPathSeparator() {
            return std::string("/");
        };

        /**
         * @param path
         * @return true if the path begins with @see getPathSeparator()
         */
        inline static bool isAbsolute(const std::string& path);

        /**
         * @param path
         * @return not isAbsolute(path)
         */
        inline static bool isRelative(const std::string& path);

        /**
         * @brief Removes duplicate `//`, and resolves stuff like `/./` and  `a/../b`
         * @param path
         * @return A new string containing the cleaned up path
         */
        static std::string cleanUpPath(const std::string& path);

        /**
         * @brief Split the path into /the/paths/individual/constituents and return as array
         * @param path to split
         * @return a vector of  [the, paths, individual, constituents]
         */
        static std::vector<std::string> splitPath(const std::string& path);

        /**
         * @brief Puts a separated path back together, separating elements using @see getPathSeparator; note that joinPath
         *        does not know if the original path was absolute or not and will always return relative paths
         * @param pathElements
         * @return Joined the path elements into a string,
         */
        static std::string joinPath(const std::vector<std::string> pathElements);

        /**
         * @brief Concatenates base and end using @see getPathSeparator(); does not clean the paths up.
         * @param base optimally, "a/path" (no trailing /)
         * @param end, optimally "and/end" (no leading /)
         * @return "base/end"
         */
        static std::string joinPath( const std::string& base, const std::string& end);

        /**
         * @brief if `/this/is/a/path`, then this function will return '/this/is/a'; use @see basename to get the last path element
         * @param path
         * @return everything but the final part of a path
         */
        static std::string dirname(const std::string& path);

        /**
         * @brief if `/this/is/a/path`, then this function will return 'path'; use @see dirname to get the path part
         * @param path
         * @return The final part of a path
         */
        static std::string basename(const std::string& path);
    };
}

#endif //SEMODIA_CONTROLENGINE_NATIVE_PATHTOOL_HPP
