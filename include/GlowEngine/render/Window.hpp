#ifndef GE_Window_HPP
#define GE_Window_HPP

#include <string>

namespace Glow 
{
    class Window
    {
        private:
            int width;
            int height;
            std::string title;
        private:
            bool hasWindow;
        public:
            static Window& getInstance();
        private:
            Window();
        public:
            static void compose();
            static void dispose();
            static bool shouldClose();
        public:
            static void setSize(int width, int height);
            static void setTitle(const std::string& title);
    };
}

#endif
