#include "raylib.h"
#include <GlowEngine/core/GlowApp.hpp>

#include <iostream>

class SandboxApp : public Glow::GlowApp
{
    public: 
        SandboxApp();
    protected:
        void onCompose() override;
        void onUpdate(float dt) override;
        void onRender() override;
        void onDispose() override;
};

SandboxApp::SandboxApp() : Glow::GlowApp(this)
{}

void SandboxApp::onCompose()
{
    std::cout << "SandboxApp::onCompose()" << std::endl; 
}

void SandboxApp::onUpdate(float dt)
{
    if(IsKeyPressed(KEY_SPACE)) {
        std::cout << "SandboxApp::onUpdate()" << std::endl;
    }     
}

void SandboxApp::onRender()
{
    DrawFPS(10, 10);    
}

void SandboxApp::onDispose()
{
    std::cout << "SandboxApp::onDispose()" << std::endl;
}

int main(int argc, char* argv[])
{
    SandboxApp app;
    app.run();
    return 0;
}
