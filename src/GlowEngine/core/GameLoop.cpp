#include <GlowEngine/core/GameLoop.hpp>
#include <GlowEngine/core/GlowApp.hpp>
#include <GlowEngine/utils/Time.hpp>
#include <GlowEngine/render/Window.hpp>

#include <raylib.h>

namespace Glow
{
    GameLoop& GameLoop::getInstance()
    {
        static GameLoop instance;
        return instance;
    }

    GameLoop::GameLoop()
    {
        this->targetFPS = 60;
        this->running = true;
    }

    void GameLoop::run()
    {
        GameLoop& gloop = GameLoop::getInstance();
        GlowApp* app = GlowApp::getInstance();
      
        Window::compose();
        SetTargetFPS(gloop.targetFPS);
        SetExitKey(KEY_NULL);

        app->compose();
        while(gloop.running && !Window::shouldClose()) {
            float dt = Time::getDeltaTime(); 
            app->update(dt);

            BeginDrawing();
                ClearBackground(BLACK);
                app->render(); 
            EndDrawing();
        }

        app->dispose();

        Window::dispose();
    }

    void GameLoop::exit()
    {
        GameLoop& gloop = GameLoop::getInstance();
        gloop.running = false;
    }
}
