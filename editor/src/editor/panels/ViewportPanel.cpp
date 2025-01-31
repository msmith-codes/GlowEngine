#include <editor/panels/ViewportPanel.hpp>

#include <imgui.h>
#include <rlImGui.h>

bool ViewportPanel::shouldRender;

void ViewportPanel::compose()
{
    ViewportPanel::shouldRender = true;
}

void ViewportPanel::updateTexture(RenderTexture& viewportTexture, Camera3D& camera)
{
    BeginTextureMode(viewportTexture);
        ClearBackground({25, 25, 25, 255});

        BeginMode3D(camera);
            // DrawGrid(16, 8.0f);

            DrawLine3D({-1024.0f, 0.0f, 0.0f}, {1024.0f, 0.0f, 0.0f}, RED);
            DrawLine3D({0.0f, -1024.0f, 0.0f}, {0.0f, 1024.0f, 0.0f}, GREEN);
            DrawLine3D({0.0f, 0.0f, -1024.0f}, {0.0f, 0.0f, 1024.0f}, BLUE);
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