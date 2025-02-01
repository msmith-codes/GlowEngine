#include <editor/panels/ViewportPanel.hpp>

#include <imgui.h>
#include <rlImGui.h>
#include <raylib.h>
#include <raymath.h>

bool ViewportPanel::shouldRender;
std::vector<Glow::Brush*> ViewportPanel::mapData;
Glow::Brush* ViewportPanel::selectedBrush;

void ViewportPanel::compose()
{
    ViewportPanel::shouldRender = true;
}

void ViewportPanel::updateTexture(RenderTexture& viewportTexture, Camera3D& camera)
{
    BeginTextureMode(viewportTexture);
        ClearBackground({50, 50, 50, 255});

        BeginMode3D(camera);
            DrawLine3D({-1024.0f, 0.0f, 0.0f}, {1024.0f, 0.0f, 0.0f}, RED);
            DrawLine3D({0.0f, -1024.0f, 0.0f}, {0.0f, 1024.0f, 0.0f}, GREEN);
            DrawLine3D({0.0f, 0.0f, -1024.0f}, {0.0f, 0.0f, 1024.0f}, BLUE);

            for(const auto& brush : ViewportPanel::mapData) {
                Color color;
                if(brush->material == "__LIGHTGRAY") { color = LIGHTGRAY; }
                else if(brush->material == "__GRAY") { color = GRAY; }
                else if(brush->material == "__DARKGRAY") { color = DARKGRAY; } 
                else if(brush->material == "__YELLOW") { color = YELLOW; }
                else if(brush->material == "__GOLD") { color = GOLD; }
                else if(brush->material == "__ORANGE") { color = ORANGE; }
                else if(brush->material == "__PINK") { color = PINK; }
                else if(brush->material == "__RED") { color = RED; }
                else if(brush->material == "__MAROON") { color = MAROON; }
                else if(brush->material == "__GREEN") { color = GREEN; }
                else if(brush->material == "__LIME") { color = LIME; }
                else if(brush->material == "__DARKGREEN") { color = DARKGREEN; }
                else if(brush->material == "__SKYBLUE") { color = SKYBLUE; }
                else if(brush->material == "__BLUE") { color = BLUE; }
                else if(brush->material == "__DARKBLUE") { color = DARKBLUE; }
                else if(brush->material == "__PURPLE") { color = PURPLE; }
                else if(brush->material == "__VIOLET") { color = VIOLET; }
                else if(brush->material == "__DARKPURPLE") { color = DARKPURPLE; }
                else if(brush->material == "__BEIGE") { color = BEIGE; }
                else if(brush->material == "__BROWN") { color = BROWN; }
                else if(brush->material == "__DARKBROWN") { color = DARKBROWN; }
                else { color = WHITE; }

                DrawCube(brush->position, brush->size.x, brush->size.y, brush->size.z, color);
            }

        EndMode3D();
    EndTextureMode();   
}

void ViewportPanel::update(RenderTexture& viewportTexture)
{
    if(IsWindowResized()) {
        UnloadRenderTexture(viewportTexture);
        viewportTexture = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
    }
}

void ViewportPanel::render(RenderTexture& viewportTexture)
{
    ImGui::Begin("Viewport", &ViewportPanel::shouldRender, ImGuiWindowFlags_NoScrollbar);
        rlImGuiImageRenderTextureFit(&viewportTexture, true);
    ImGui::End();
}

void ViewportPanel::setMapData(const std::vector<Glow::Brush*>& brushes)
{
    ViewportPanel::mapData = brushes;
}

Glow::Brush* ViewportPanel::getSelectedBrush()
{
    return ViewportPanel::selectedBrush;
}

void ViewportPanel::setSelectedBrush(Glow::Brush* brush)
{
    ViewportPanel::selectedBrush = brush;
}
