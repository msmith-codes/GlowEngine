#include <GlowEngine/render/Window.hpp>
#include <GlowEngine/core/GlowApp.hpp>

#include <iostream>

#include <raylib.h>
#include <raymath.h>

#include <imgui.h>
#include <rlImGui.h>

class EditorApp: public Glow::GlowApp
{
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
}

void EditorApp::onCompose()
{
    std::cout << "EditorApp::onCompose()" << std::endl; 
    rlImGuiSetup(true);

    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
}

void EditorApp::onUpdate(float dt)
{
    if(IsKeyPressed(KEY_SPACE)) {
        std::cout << "EditorApp::onUpdate()" << std::endl;
    }     
}

void EditorApp::onRender()
{
    DrawFPS(10, 10);
    rlImGuiBegin();
        ImGui::DockSpaceOverViewport(0,  NULL, ImGuiDockNodeFlags_PassthruCentralNode);
        ImGui::ShowDemoWindow();
    rlImGuiEnd();
}

void EditorApp::onDispose()
{
    std::cout << "EditorApp::onDispose()" << std::endl;
}

int main(int argc, char* argv[])
{
    EditorApp app;
    app.run();

    return 0;
}
