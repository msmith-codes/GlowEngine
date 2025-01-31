#ifndef GE_HierarchyPanel_HPP
#define GE_HierarchyPanel_HPP

#include <GlowEngine/utils/MapLoader.hpp>
#include <vector>


class HierarchyPanel
{
    public:
        static std::vector<Glow::Brush> mapData;
    public:
        static void render();
    public:
        static void setMapData(const std::vector<Glow::Brush>& brushes);
};

#endif