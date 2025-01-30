#ifndef GE_GlowApp_HPP
#define GE_GlowApp_HPP

#include <raylib.h>

namespace Glow 
{
    class GlowApp
    {
        private:
            static GlowApp* instance;
        public:
            static GlowApp* getInstance();
        protected:
            GlowApp(GlowApp* instance);
        public:
            virtual ~GlowApp();
        protected:
            virtual void onCompose() = 0;
            virtual void onUpdate(float dt) = 0;
            virtual void onRender() = 0;
            virtual void onDispose() = 0;
        public:
            void compose();
            void update(float dt);
            void render();
            void dispose();
            void run();
    };
}

#endif
