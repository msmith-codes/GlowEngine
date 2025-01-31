#include <GlowEngine/render/Window.hpp>
#include <GlowEngine/core/GlowApp.hpp>

#include <editor/panels/MenuBar.hpp>
#include <editor/panels/OpenProjectPopup.hpp>
#include <editor/panels/ViewportPanel.hpp>
#include <editor/panels/InspectorPanel.hpp>
#include <editor/panels/HierarchyPanel.hpp>
#include <editor/panels/ToolbarPanel.hpp>
#include <editor/panels/FileExplorerPanel.hpp>

#include <iostream>

#include <raylib.h>
#include <raymath.h>

#include <imgui.h>
#include <rlImGui.h>

class EditorApp: public Glow::GlowApp
{
    private:
        bool shouldShowViewport;
        RenderTexture viewportTexture;
        Camera3D editorCamera;
        int viewWidth;
        int viewHeight;
    public: 
        EditorApp();
    protected:
        void onCompose() override;
        void onUpdate(float dt) override;
        void onRender() override;
        void onDispose() override;
};

EditorApp::EditorApp() : Glow::GlowApp(this)
{
    Glow::Window::setSize(1280, 720);
    Glow::Window::setTitle("GlowEditor");
    this->shouldShowViewport = true;
}

void EditorApp::onCompose()
{
    std::cout << "EditorApp::onCompose()" << std::endl; 
    rlImGuiSetup(true);

    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    this->viewportTexture = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());

    this->editorCamera.fovy = 45.0f;
    this->editorCamera.up = { 0.0f, 1.0f, 0.0f };
    this->editorCamera.position = { 15.0f, 15.0f, 15.0f };
    this->editorCamera.target = { 0.0f, 0.0f, 0.0f };
    this->editorCamera.projection = CAMERA_PERSPECTIVE;
}

void EditorApp::onUpdate(float dt)
{
    // UpdateCamera(&this->editorCamera, CAMERA_ORBITAL);

    ViewportPanel::update(this->viewportTexture);
    ViewportPanel::updateTexture(this->viewportTexture, this->editorCamera);
}

void EditorApp::onRender()
{
    DrawFPS(10, 10);
    rlImGuiBegin();
        ImGui::DockSpaceOverViewport(0,  NULL, ImGuiDockNodeFlags_PassthruCentralNode);

        ViewportPanel::render(this->viewportTexture);
        OpenProjectPopup::render();
        MenuBar::render();
        ToolbarPanel::render();
        HierarchyPanel::render();
        InspectorPanel::render();
        FileExplorerPanel::render();        

    rlImGuiEnd();
}

void EditorApp::onDispose()
{
    UnloadRenderTexture(this->viewportTexture);
}

int main(int argc, char* argv[])
{
    EditorApp app;
    app.run();

    return 0;
}
