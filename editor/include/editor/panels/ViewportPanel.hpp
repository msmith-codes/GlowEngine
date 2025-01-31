#ifndef GE_ViewportPanel_HPP
#define GE_ViewportPanel_HPP

#include <GlowEngine/utils/MapLoader.hpp>

#include <vector>
#include <raylib.h>

class ViewportPanel
{
    private:
        static bool shouldRender;
        static std::vector<Glow::Brush> mapData;
        static Glow::Brush* selectedBrush;
    public:
        static void compose();
        static void updateTexture(RenderTexture& viewportTexture, Camera3D& camera);
        static void update(RenderTexture& viewportTexture);
        static void render(RenderTexture& viewportTexture);
        static void setMapData(const std::vector<Glow::Brush>& brushes);
        static Glow::Brush* getSelectedBrush();
        static void setSelectedBrush(Glow::Brush* brush);
};

#endif