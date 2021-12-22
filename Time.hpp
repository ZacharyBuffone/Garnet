//
// Created by Zachary Buffone on 12/13/21.
//

#ifndef GARNET_ENGINE_TIME_HPP
#define GARNET_ENGINE_TIME_HPP

#include <chrono>

namespace Garnet {

    class Time {
    private:
        inline static std::chrono::time_point<std::chrono::system_clock> lastUpdateTime;
        inline static float deltaTime;

    public:
        static void Update() {
            auto now = std::chrono::system_clock::now();
            std::chrono::duration<float> delta = now - lastUpdateTime;
            deltaTime = delta.count();
            lastUpdateTime = now;
        }

        static void Initialize() {
            lastUpdateTime = std::chrono::system_clock::now();
            deltaTime = 1.0f/60.0f;
        }

        static float DeltaTime()  {
            return Time::deltaTime;
        }

    };

}


#endif //GARNET_ENGINE_TIME_HPP
