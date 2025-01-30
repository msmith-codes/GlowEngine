#ifndef GE_GameLoop_HPP
#define GE_GameLoop_HPP

namespace Glow
{
    class GameLoop
    {
        private:
            bool running;
            int targetFPS;
        public:
            static GameLoop& getInstance();
        private:
            GameLoop();
        public:
            static void run();
            static void exit();
    };
}

#endif
