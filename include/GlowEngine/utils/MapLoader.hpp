#ifndef GE_MapLoader_HPP
#define GE_MapLoader_HPP

#include <string>
#include <vector>

#include <raylib.h>
#include <toml.hpp>

namespace Glow
{
    struct Brush 
    {
        std::string name;
        std::string material;
        Vector3 position;
        Vector3 size;
        Vector3 rotation; 
    };


    class MapLoader
    {
        private:
            std::string name;
            std::string author;
            std::string version;
            Vector3 dimesions;
            std::vector<Brush> brushes;
        public:
            MapLoader(const std::string& path);
        public:
            std::vector<Brush> getBrushes() const;
    };
}

#endif