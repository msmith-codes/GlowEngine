#include <GlowEngine/core/GlowApp.hpp>
#include <GlowEngine/core/GameLoop.hpp>

namespace Glow 
{
    GlowApp* GlowApp::instance = nullptr;

    GlowApp* GlowApp::getInstance()
    {
        return GlowApp::instance;
    }
    
    GlowApp::GlowApp(GlowApp* instance)
    {
        GlowApp::instance = instance;
    }
    
    GlowApp::~GlowApp()
    {
        delete GlowApp::instance;
    }
    
    void GlowApp::compose()
    {
        this->onCompose();
    }

    void GlowApp::update(float dt)
    {
        this->onUpdate(dt);
    }

    void GlowApp::render()
    {
        this->onRender();
    }

    void GlowApp::dispose()
    {
        this->onDispose();
    }

    void GlowApp::run()
    {
        GameLoop::run();
    }
}
