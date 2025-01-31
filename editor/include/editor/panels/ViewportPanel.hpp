#ifndef GE_ViewportPanel_HPP
#define GE_ViewportPanel_HPP

#include <raylib.h>

class ViewportPanel
{
    private:
        static bool shouldRender;
    public:
        static void compose();
        static void updateTexture(RenderTexture& viewportTexture, Camera3D& camera);
        static void update(RenderTexture& viewportTexture);
        static void render(RenderTexture& viewportTexture);
};

#endif