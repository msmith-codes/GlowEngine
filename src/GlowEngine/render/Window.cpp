#include "raylib.h"
#include <GlowEngine/render/Window.hpp>

namespace Glow
{
    Window& Window::getInstance()
    {
        static Window instance;
        return instance;
    }
    
    Window::Window()
    {
        this->width = 800;
        this->height = 600;
        this->title = "GlowEngine";
        this->hasWindow = false;
    }

    void Window::compose()
    {
        Window& win = Window::getInstance();
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);
        InitWindow(win.width, win.height, win.title.c_str());
        win.hasWindow = true;
    }

    void Window::dispose()
    {
        CloseWindow();
    }

    bool Window::shouldClose()
    {
        return WindowShouldClose();
    }

    void Window::setSize(int width, int height)
    {
        Window& win = Window::getInstance();
        win.width = width;
        win.height = height;
        if(win.hasWindow) {
            SetWindowSize(win.width, win.height);
        }
    }

    void Window::setTitle(const std::string &title)
    {
        Window& win = Window::getInstance();
        win.title = title;
        if(win.hasWindow) {
            SetWindowTitle(win.title.c_str());
        }
    }
}
