#include "raylib.h"
#include <GlowEngine/utils/Time.hpp>

namespace Glow 
{
    float Time::getDeltaTime()
    {
        return GetFrameTime();
    }
}
