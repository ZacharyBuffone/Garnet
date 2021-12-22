//
// Created by Zachary Buffone on 12/7/21.
//

#ifndef GARNET_ENGINE_MATHF_HPP
#define GARNET_ENGINE_MATHF_HPP
#include <glm.hpp>

namespace Garnet::Mathf {

    inline float Lerp(float a, float b, float t) {
        return a + (b-a) * t;
    }

    const float DEG_2_RAD = 3.1415926535  / 180.0;
    const float RAD_2_DEG = 180.0 / 3.1415926535;
    const float TAU = 3.1415926535 * 2.0;

    inline glm::vec3 vec3Zero() {
        return {0.0,0.0,0.0};
    }

    inline glm::vec3 vec3One() {
        return {1.0,1.0,1.0};
    }

    inline glm::quat quatIdentity() {
        return {1.0f, 0.0f, 0.0f, 0.0f};
    }

    inline glm::vec3 vec3Up() {
        return {0.f,1.f,0.f};
    }
    inline glm::vec3 vec3Left() {
        return {1.f,0.f,0.f};
    }
    inline glm::vec3 vec3Forward() {
        return {0.f,0.f,1.f};
    }

}

#endif //GARNET_ENGINE_MATHF_HPP
